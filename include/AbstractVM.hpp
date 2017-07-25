//
// AbstractVM.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 2:57:48 PM 2017 guillaume.mardon@epitech.eu
// Last update Wed Jul 25 11:45:50 AM 2017 guillaume.mardon@epitech.eu
//
#ifndef _ABSTRACT_VM_HPP_
#define _ABSTRACT_VM_HPP_
#include <iostream>
#include <stack>
#include <map>
#include <list>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <regex>
#include <string>
#include <exception>

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

static inline bool equals_ignore_case(const std::string& a, const std::string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

static inline std::string toLower(std::string str)
{
    std::string newstr(str);
    std::transform(newstr.begin(), newstr.end(), newstr.begin(), ::tolower);
    return newstr;
}
#endif