#ifndef _DOUBLE_HPP_
#define _DOUBLE_HPP_
class Double : public Operand<double>
{
public:
    Double(const std::string & value);
    ~Double();
};
#endif
