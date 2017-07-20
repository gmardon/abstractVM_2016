#include "Factory.hpp"

Factory::Factory()
{
	operands[Int8] = &Factory::createInt8;
	operands[Int16] = &Factory::createInt16;
	operands[Int32] = &Factory::createInt32;
	operands[Float] = &Factory::createFloat;
	operands[Double] = &Factory::createDouble;
}

IOperand const* Factory::createOperand(eOperandType type, std::string const& value) const
{
	IOperand const* (Factory::*f)(std::string const & value) const;
	f = create.at(type);
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
	return (new Operand<double>(value, Double, 14, this));
}

Factory::~Factory()
{

}