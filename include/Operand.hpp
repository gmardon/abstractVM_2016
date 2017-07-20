#ifndef _OPERAND_HPP_
#define _OPERAND_HPP_
#include "IOperand.hpp"
template <typename T>
class 	Operand : public IOperand
{
    protected:
    eOperandType	_type;
    std::string 	_str;

    public:
        virtual std::string const & toString() const;

        virtual int getPrecision() const;
        virtual eOperandType getType() const;

        virtual IOperand * operator+(const IOperand &rhs) const;
        virtual IOperand * operator-(const IOperand &rhs) const;
        virtual IOperand * operator*(const IOperand &rhs) const;
        virtual IOperand * operator/(const IOperand &rhs) const;
        virtual IOperand * operator%(const IOperand &rhs) const;

        Operand(eOperandType type, const std::string & value);
        virtual ~Operand();
};
#endif