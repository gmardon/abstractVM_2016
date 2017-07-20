#include "Factory.hpp"

Factory::Factory()
{
	operands[INT8] = &Factory::createInt8;
	operands[INT16] = &Factory::createInt16;
	operands[INT32] = &Factory::createInt32;
	operands[FLOAT] = &Factory::createFloat;
	operands[DOUBLE] = &Factory::createDouble;
	operands[BIGDECIMAL] = &Factory::createBigDecimal;
}

IOperand const* Factory::createOperand(eOperandType type, std::string const& value) const
{
	IOperand const* (Factory::*f)(std::string const & value) const;
	//f = create.at(type);
	return ((*this.*f)(value));
}

IOperand const* Factory::createInt8( std::string const & value ) const
{
	return (new Operand<char>(value, Int8, 0, this));
}

IOperand const* Factory::createInt16( std::string const & value ) const
{
	return (new Operand<short int>(value, Int16, 0, this));
}

IOperand const* Factory::createInt32( std::string const & value ) const
{
	return (new Operand<int>(value, Int32, 0, this));
}

IOperand const* Factory::createFloat( std::string const & value ) const
{
	return (new Operand<float>(value, Float, 7, this));
}

IOperand const* Factory::createDouble( std::string const & value ) const
{
	return (new Operand<double>(value, Double, 15, this));
}

IOperand const* Factory::createBigDecimal( std::string const & value ) const
{
	return (new Operand<long int>(value, Double, 200, this));
}

Factory::~Factory()
{

}