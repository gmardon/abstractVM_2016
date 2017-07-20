#ifndef _FLOAT_HPP_
#define _FLOAT_HPP_
class Float : public Operand<float>
{
public:
    Float(const std::string & value);
    ~Float();
};
#endif