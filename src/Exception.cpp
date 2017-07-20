//
// Exception.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 9:34:43 AM 2017 guillaume.mardon@epitech.eu
// Last update Fri Jul 20 9:59:55 AM 2017 guillaume.mardon@epitech.eu
//
#include "Exception.hpp"

Exception::Exception(const std::string &msg) throw()
{
  this->_msg = msg;
}

Exception::~Exception() throw()
{
}

const char *Exception::what() const throw()
{
  return (this->_msg.c_str());
}