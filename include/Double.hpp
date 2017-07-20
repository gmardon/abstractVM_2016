//
// Double.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 3:05:23 PM 2017 guillaume.mardon@epitech.eu
// Last update Fri Jul 20 3:05:23 PM 2017 guillaume.mardon@epitech.eu
//

#ifndef _DOUBLE_HPP_
#define _DOUBLE_HPP_
class Double : public Operand<double>
{
public:
    Double(const std::string & value);
    ~Double();
};
#endif
