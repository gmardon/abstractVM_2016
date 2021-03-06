//
// Float.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 2:57:18 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 11:12:19 AM 2017 guillaume.mardon@epitech.eu
//
#ifndef _FLOAT_HPP_
#define _FLOAT_HPP_
#include "Operand.hpp"

class Float : public Operand<float>
{
public:
    Float(const std::string & value);
    ~Float();
};

template <>
int Operand<float>::getPrecision() const
{
	return 7;
}

template <>
eOperandType Operand<float>::getType() const
{
	return FLOAT;
}

#endif