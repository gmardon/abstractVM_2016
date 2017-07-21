//
// Int16.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 3:05:41 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 10:02:42 AM 2017 guillaume.mardon@epitech.eu
//
#ifndef _INT16_HPP_
#define _INT16_HPP_
#include "Operand.hpp"

class Int16 : public Operand<int16_t>
{
public:
    Int16(const std::string & value);
    ~Int16();

    int getPrecision() const
    {
        return 0;
    }

    eOperandType getType() const
    {
        return INT16;
    }
};
#endif