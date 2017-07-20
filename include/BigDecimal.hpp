#ifndef _BIG_DECIMAL_HPP_
#define _BIG_DECIMAL_HPP_
class BigDecimal : public Operand<int64_t>
{
public:
    BigDecimal(const std::string & value);
    ~BigDecimal();
};
#endif