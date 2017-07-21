//
// Operand.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 4:22:58 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 10:46:19 AM 2017 guillaume.mardon@epitech.eu
//
#include "Operand.hpp"

template <typename T>
Operand<T>::Operand(eOperandType type, const std::string &value)
{
	this->type = type;
	this->value = value;
}

template <typename T>
Operand<T>::~Operand()
{
}

template <typename T>
std::string const &Operand<T>::toString(void) const
{
	return this->value;
}

template <typename T>
IOperand *Operand<T>::operator+(IOperand const &rhs) const
{
	/*if (this->getPrecision() < rhs.getPrecision()) 
		return (rhs + *this);
	return ret_val;*/
	return NULL;
}

template <>
int Operand<int8_t>::getPrecision() const
{
	return 0;
}

template <>
eOperandType Operand<int8_t>::getType() const
{
	return INT8;
}

template <>
int Operand<int16_t>::getPrecision() const
{
	return 0;
}

template <>
eOperandType Operand<int16_t>::getType() const
{
	return INT16;
}

template <>
int Operand<int32_t>::getPrecision() const
{
	return 0;
}

template <>
eOperandType Operand<int32_t>::getType() const
{
	return INT32;
}

template <>
int Operand<int64_t>::getPrecision() const
{
	return 0;
}

template <>
eOperandType Operand<int64_t>::getType() const
{
	return BIGDECIMAL;
}

template <>
int Operand<float>::getPrecision() const
{
	return 0;
}

template <>
eOperandType Operand<float>::getType() const
{
	return FLOAT;
}

template <>
int Operand<double>::getPrecision() const
{
	return 0;
}

template <>
eOperandType Operand<double>::getType() const
{
	return DOUBLE;
}

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<int64_t>;
template class Operand<float>;
template class Operand<double>;