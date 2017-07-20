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
	f = operands.at(type);
	return ((*this.*f)(value));
}

IOperand const* Factory::createInt8( std::string const & value ) const
{
	return (new Int8(value));
}

IOperand const* Factory::createInt16( std::string const & value ) const
{
	return (new Int16(value));
}

IOperand const* Factory::createInt32( std::string const & value ) const
{
	return (new Int32(value));
}

IOperand const* Factory::createFloat( std::string const & value ) const
{
	return (new Float(value));
}

IOperand const* Factory::createDouble( std::string const & value ) const
{
	return (new Double(value));
}

IOperand const* Factory::createBigDecimal( std::string const & value ) const
{
	return (new BigDecimal(value));
}

Factory::~Factory()
{

}