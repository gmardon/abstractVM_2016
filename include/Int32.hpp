//
// Int32.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 3:05:47 PM 2017 guillaume.mardon@epitech.eu
// Last update Fri Jul 20 3:05:52 PM 2017 guillaume.mardon@epitech.eu
//
#ifndef _INT32_HPP_
#define _INT32_HPP_
class Int32 : public Operand<int32_t>
{
public:
    Int32(const std::string & value);
    ~Int32();
};
#endif