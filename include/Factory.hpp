//
// Factory.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 2:57:28 PM 2017 guillaume.mardon@epitech.eu
// Last update Fri Jul 20 3:04:32 PM 2017 guillaume.mardon@epitech.eu
//
#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_
#include <string>
#include <map>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "BigDecimal.hpp"
#include "Double.hpp"

class Factory
{
public:
	Factory();
	Factory(const Factory&);
	const Factory& operator=(const Factory&);
	IOperand const *createOperand(eOperandType type, std::string const & value) const;

	~Factory();

private:
	IOperand const *createInt8(std::string const & value) const;
	IOperand const *createInt16(std::string const & value) const;
	IOperand const *createInt32(std::string const & value) const;
	IOperand const *createFloat(std::string const & value) const;
	IOperand const *createDouble(std::string const & value) const;
	IOperand const *createBigDecimal(std::string const & value) const;
	
	std::map<eOperandType, IOperand const* (Factory::*)(std::string const & value) const> operands;
};
#endif