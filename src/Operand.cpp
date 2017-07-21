//
// Operand.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 4:22:58 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 7:50:05 PM 2017 guillaume.mardon@epitech.eu
//
#include "Operand.hpp"
#include "Factory.hpp"

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
IOperand const *Operand<T>::operator+(IOperand const &target) const
{
	if (this->getPrecision() < target.getPrecision()) 
		return (target + *this);
	T source_value = static_cast<T>(stod(this->value));
	T target_value = static_cast<T>(stod(target.toString()));
	// check overflow before anything
	Factory *factory = new Factory();
	const IOperand *operand = factory->createOperand(this->getType(), std::to_string(target_value + source_value));
	delete factory;
	return operand;
}

template <typename T>
IOperand const *Operand<T>::operator-(IOperand const &target) const
{
	return NULL;
}

template <typename T>
IOperand const *Operand<T>::operator*(IOperand const &target) const
{
	if (this->getPrecision() < target.getPrecision()) 
		return (target + *this);
	T source_value = static_cast<T>(stod(this->value));
	T target_value = static_cast<T>(stod(target.toString()));
	// check overflow before anything
	Factory *factory = new Factory();
	const IOperand *operand = factory->createOperand(this->getType(), std::to_string(target_value * source_value));
	delete factory;
	return operand;
}

template <typename T>
IOperand const *Operand<T>::operator/(IOperand const &target) const
{
	return NULL;
}

template <typename T>
IOperand const *Operand<T>::operator%(IOperand const &target) const
{
	return NULL;
}