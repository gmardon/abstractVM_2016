#include "Float.hpp"

AbstractVM::Operand::Float::Float(const std::string & value) : Operand(FLOAT, value)
{
}

AbstractVM::Operand::Float::~Float()
{
}