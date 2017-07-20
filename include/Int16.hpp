#ifndef _INT16_HPP_
#define _INT16_HPP_
class Int16 : public Operand<int16_t>
{
public:
    Int16(const std::string & value);
    ~Int16();
};
#endif