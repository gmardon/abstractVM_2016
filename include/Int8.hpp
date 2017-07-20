#ifndef _INT8_HPP_
#define _INT8_HPP_
class Int8 : public Operand<int8_t>
{
public:
    Int8(const std::string & value);
    ~Int8();
};
#endif