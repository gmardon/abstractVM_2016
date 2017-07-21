//
// BigDecimal.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 2:58:02 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 11:13:06 AM 2017 guillaume.mardon@epitech.eu
//
#ifndef _BIG_DECIMAL_HPP_
#define _BIG_DECIMAL_HPP_
#include "Operand.hpp"

class BigDecimal : public Operand<int64_t>
{
public:
    BigDecimal(const std::string & value);
    ~BigDecimal();
};

template <>
int Operand<int64_t>::getPrecision() const
{
	return 200;
}

template <>
eOperandType Operand<int64_t>::getType() const
{
	return BIGDECIMAL;
}
#endif