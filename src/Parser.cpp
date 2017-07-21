//
// Parser.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Sat Jul 21 1:51:56 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 1:52:00 PM 2017 guillaume.mardon@epitech.eu
//
#include "Parser.hpp"

void parseFile(std::string filename)
{
    std::ifstream file;
    std::string instruction;
    std::string value;
    size_t pos;

    file.open(filename.c_str());
    if (file.is_open() == false)
        throw Exception("File does not exist");

    while (file.good() == true && file.eof() != true && instruction != ";;")
    {
        getline(file, instruction, '\n');
        if (instruction[0] == ';')
        {
        }
        else if ((pos = instruction.find(' ')) != instruction.npos)
        {
            value = instruction.substr(pos + 1, instruction.npos - 1);
            instruction = instruction.substr(0, pos);
        }
        else
        {
        }
    }
    file.close();
    if (instruction != "exit")
        throw Exception("Last instruction should be exit");
}