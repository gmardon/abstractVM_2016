//
// IOperand.hh for IOperand in /home/bettin_j//Documents/Abstract-Vm/include
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Sat Feb  9 09:32:15 2013 jordan bettin
// Last update Fri Jul 20 2:49:29 PM 2017 guillaume.mardon@epitech.eu
//

#ifndef _IOPERAND_HPP_
#define	_IOPERAND_HPP_
#include <string>
#include <iostream>
#include <exception>

typedef enum eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL,
    UNKNOWN,
  }		eOperandType;

class	IOperand
{
public:
    virtual std::string const & toString() const = 0;
    virtual int getPrecision() const = 0;
    virtual eOperandType getType() const = 0;
    virtual IOperand * operator+(const IOperand & rhs) const = 0;
    virtual IOperand * operator-(const IOperand & rhs) const = 0;
    virtual IOperand * operator*(const IOperand & rhs) const = 0;
    virtual IOperand * operator/(const IOperand & rhs) const = 0;
    virtual IOperand * operator%(const IOperand & rhs) const = 0;
    virtual ~IOperand() {}
};

#endif