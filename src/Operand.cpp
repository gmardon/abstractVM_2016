//
// Operand.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 4:22:58 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 9:56:38 AM 2017 guillaume.mardon@epitech.eu
//
#include "Operand.hpp"

template<typename T>
Operand<T>::Operand(eOperandType type, const std::string & value)
{
    this->type = type;
    this->value = value;
}

template<typename T>
Operand<T>::~Operand()
{

}

template<typename T> 
std::string const & Operand<T>::toString( void ) const {
	return this->value;
}

template<typename T>
IOperand * Operand<T>::operator+( IOperand const & rhs ) const {
	/*if (this->getPrecision() < rhs.getPrecision()) 
		return (rhs + *this);
	return ret_val;*/
	return NULL;
}

template Operand<int8_t>::Operand(eOperandType type, const std::string & value);
template Operand<int16_t>::Operand(eOperandType type, const std::string & value);
template Operand<int32_t>::Operand(eOperandType type, const std::string & value);
template Operand<int64_t>::Operand(eOperandType type, const std::string & value);
template Operand<float>::Operand(eOperandType type, const std::string & value);
template Operand<double>::Operand(eOperandType type, const std::string & value);
