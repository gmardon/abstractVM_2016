//
// Operand.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 4:22:58 PM 2017 guillaume.mardon@epitech.eu
// Last update Tue Jul 24 2:16:52 PM 2017 guillaume.mardon@epitech.eu
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
	const IOperand *operand;
	Factory *factory = new Factory();
	T source_value = static_cast<T>(stod(this->value));
	T target_value = static_cast<T>(stod(target.toString()));
	// check overflow before anything
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), std::to_string(target_value + source_value));
	else
		operand = factory->createOperand(target.getType(), std::to_string(target_value + source_value));
	delete factory;
	return operand;
}

template <typename T>
IOperand const *Operand<T>::operator-(IOperand const &target) const
{
	const IOperand *operand;
	Factory *factory = new Factory();
	T source_value = static_cast<T>(stod(this->value));
	T target_value = static_cast<T>(stod(target.toString()));
	// check overflow before anything
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), std::to_string(source_value - target_value));
	else
		operand = factory->createOperand(target.getType(), std::to_string(source_value - target_value));
	delete factory;
	return operand;
}

template <typename T>
IOperand const *Operand<T>::operator*(IOperand const &target) const
{
	const IOperand *operand;
	Factory *factory = new Factory();
	T source_value = static_cast<T>(stod(this->value));
	T target_value = static_cast<T>(stod(target.toString()));
	// check overflow before anything
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), std::to_string(source_value * target_value));
	else
		operand = factory->createOperand(target.getType(), std::to_string(source_value * target_value));
	delete factory;
	return operand;
}

template <typename T>
IOperand const *Operand<T>::operator/(IOperand const &target) const
{
	if (atof(target.toString().c_str()) == 0 || atof(this->toString().c_str()) == 0)
    	throw Exception("Division by zero !");
	const IOperand *operand;
	Factory *factory = new Factory();
	T source_value = static_cast<T>(stod(this->value));
	T target_value = static_cast<T>(stod(target.toString()));
	// check overflow before anything
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), std::to_string(source_value / target_value));
	else
		operand = factory->createOperand(target.getType(), std::to_string(source_value / target_value));
	delete factory;
	return operand;
}

template <typename T>
IOperand const *Operand<T>::operator%(IOperand const &target) const
{
	if (atof(target.toString().c_str()) == 0 || atof(this->toString().c_str()) == 0)
    	throw Exception("Modulo by zero !");
	if (type == FLOAT || target.getType() == FLOAT)
        throw Exception("Modulo with float !");
	if (type == DOUBLE || target.getType() == DOUBLE)
        throw Exception("Modulo with double !");
	const IOperand *operand;
	Factory *factory = new Factory();
	T source_value = static_cast<T>(stod(this->value));
	T target_value = static_cast<T>(stod(target.toString()));
	// check overflow before anything
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), std::to_string((int)source_value % (int) target_value));
	else
		operand = factory->createOperand(target.getType(), std::to_string((int)source_value % (int) target_value));
	delete factory;
	return operand;
}