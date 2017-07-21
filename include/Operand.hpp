//
// Operand.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 3:06:16 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 1:43:53 PM 2017 guillaume.mardon@epitech.eu
//
#ifndef _OPERAND_HPP_
#define _OPERAND_HPP_
#include "IOperand.hpp" 

template <typename T>
class Operand : public IOperand
{
    public:
        virtual std::string const & toString() const;

        virtual int getPrecision() const;
        virtual eOperandType getType() const;

        IOperand const * operator+(const IOperand &target) const;
        IOperand const * operator-(const IOperand &target) const;
        IOperand const * operator*(const IOperand &target) const;
        IOperand const * operator/(const IOperand &target) const;
        IOperand const * operator%(const IOperand &target) const;

        Operand(eOperandType type, const std::string & value);
        ~Operand();

    protected:
        std::string value;
        eOperandType type;
};

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<int64_t>;
template class Operand<float>;
template class Operand<double>;
#endif