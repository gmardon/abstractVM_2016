//
// Operand.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 4:22:58 PM 2017 guillaume.mardon@epitech.eu
// Last update Wed Jul 25 1:51:56 PM 2017 guillaume.mardon@epitech.eu
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
	double source_value = static_cast<double>(stod(this->value));
	double target_value = static_cast<double>(stod(target.toString()));
	std::string result = std::to_string(source_value + target_value);
	// check overflow before anything
	if (this->getPrecision() + target.getPrecision() == 0)
		result = result.substr(0, result.find(".", 0));
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), result);
	else
		operand = factory->createOperand(target.getType(), result);
	delete factory;
	return operand;
}

template <typename T>
IOperand const *Operand<T>::operator-(IOperand const &target) const
{
	const IOperand *operand;
	Factory *factory = new Factory();
	double source_value = static_cast<double>(stod(this->value));
	double target_value = static_cast<double>(stod(target.toString()));
	std::string result = std::to_string(source_value - target_value);
	if (this->getPrecision() + target.getPrecision() == 0)
		result = result.substr(0, result.find(".", 0));
	// check overflow before anything
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), result);
	else
		operand = factory->createOperand(target.getType(), result);
	delete factory;
	return operand;
}

template <typename T>
IOperand const *Operand<T>::operator*(IOperand const &target) const
{
	const IOperand *operand;
	Factory *factory = new Factory();
	double source_value = static_cast<double>(stod(this->value));
	double target_value = static_cast<double>(stod(target.toString()));
	std::string result = std::to_string(source_value * target_value);
	if (this->getPrecision() + target.getPrecision() == 0)
		result = result.substr(0, result.find(".", 0));
	// check overflow before anything
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), result);
	else
		operand = factory->createOperand(target.getType(), result);
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
	double source_value = static_cast<double>(stod(this->value));
	double target_value = static_cast<double>(stod(target.toString()));
	std::string result = std::to_string(source_value / target_value);
	if (this->getPrecision() + target.getPrecision() == 0)
		result = result.substr(0, result.find(".", 0));
	// check overflow before anything
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), result);
	else
		operand = factory->createOperand(target.getType(), result);
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
	uint64_t source_value = static_cast<int>(stod(this->value));
	uint64_t target_value = static_cast<int>(stod(target.toString()));
	std::string result = std::to_string(source_value % target_value);
	if (this->getPrecision() + target.getPrecision() == 0)
		result = result.substr(0, result.find(".", 0));
	// check overflow before anything
	if (this->getPrecision() > target.getPrecision()) 
		operand = factory->createOperand(this->getType(), result);
	else
		operand = factory->createOperand(target.getType(), result);
	delete factory;
	return operand;
}