//
// Exception.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 3:05:30 PM 2017 guillaume.mardon@epitech.eu
// Last update Wed Jul 25 11:44:40 AM 2017 guillaume.mardon@epitech.eu
//
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