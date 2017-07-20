#ifndef _INT32_HPP_
#define _INT32_HPP_
class Int32 : public Operand<int32_t>
{
public:
    Int32(const std::string & value);
    ~Int32();
};
#endif