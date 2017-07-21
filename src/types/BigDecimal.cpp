//
// BigDecimal.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src/types
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Sat Jul 21 1:52:42 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 1:52:46 PM 2017 guillaume.mardon@epitech.eu
//
#include "BigDecimal.hpp"

BigDecimal::BigDecimal(const std::string & value) : Operand(BIGDECIMAL, value)
{
}

BigDecimal::~BigDecimal()
{
}