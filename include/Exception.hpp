#ifndef	_EXCEPTION_HPP_
#define	_EXCEPTION_HPP_
#include <iostream>
#include <exception>

class Exception : public std::exception
{
    std::string	_msg;
  
public:
    Exception (std::string const &msg) throw();
    virtual ~Exception() throw();
    virtual const char* what() const throw();
};

#endif