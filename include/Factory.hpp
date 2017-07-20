
#include <string>
#include <map>
#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "BigDecimal.hpp"
class Factory
{
public:
	Factory();
	Factory(const Factory&);
	const Factory& operator=(const Factory&);
	IOperand const *createOperand(eOperandType type, std::string const & value) const;

	~Factory();

private:
	IOperand const *createInt8(std::string const & value) const;
	IOperand const *createInt16(std::string const & value) const;
	IOperand const *createInt32(std::string const & value) const;
	IOperand const *createFloat(std::string const & value) const;
	IOperand const *createDouble(std::string const & value) const;

	std::map<eOperandType, IOperand const* (Factory::*)(std::string const & value) const> operands;
};