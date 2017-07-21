//
// Int32.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 3:05:47 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 11:13:23 AM 2017 guillaume.mardon@epitech.eu
//
#ifndef _INT32_HPP_
#define _INT32_HPP_
#include "Operand.hpp"

class Int32 : public Operand<int32_t>
{
public:
    Int32(const std::string & value);
    ~Int32();
};

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
#endif