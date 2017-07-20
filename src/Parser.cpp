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