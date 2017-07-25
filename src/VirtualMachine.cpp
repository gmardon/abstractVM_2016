//
// VirtualMachine.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Sat Jul 21 1:46:44 PM 2017 guillaume.mardon@epitech.eu
// Last update Tue Jul 24 2:12:34 PM 2017 guillaume.mardon@epitech.eu
//
#include "VirtualMachine.hpp"

VirtualMachine::VirtualMachine()
{
    this->handlers["exit"] = &VirtualMachine::exit;
    this->handlers["add"] = &VirtualMachine::add;
    this->handlers["push"] = &VirtualMachine::push;
    this->handlers["pop"] = &VirtualMachine::pop;
    this->handlers["mul"] = &VirtualMachine::mul;
    this->handlers["dump"] = &VirtualMachine::dump;
    this->handlers["assert"] = &VirtualMachine::assert;
    this->handlers["print"] = &VirtualMachine::print;
    this->handlers["sub"] = &VirtualMachine::sub;
    this->handlers["mod"] = &VirtualMachine::mod;
    this->handlers["div"] = &VirtualMachine::div;
    this->handlers["clear"] = &VirtualMachine::clear;
}

std::vector<std::pair<std::string, const IOperand*>> VirtualMachine::fromFile(std::string filename)
{
    Factory *factory = new Factory();
    std::ifstream file;
    std::string line;
    std::string value;
    std::string type;
    std::vector<std::pair<std::string, const IOperand*>> instructions;
    std::regex regex("^(push[\\s\\t]*(int8\\(([−]?[0-9]+)\\)|int16\\(([−]?[0-9]+)\\)|float\\(([−]?[0-9]+[.]?[0-9]*)\\)|bigdecimal\\(([−]?[0-9]+[.]?[0-9]*)\\)|int32\\(([−]?[0-9]+)\\)|double\\(([−]?[0-9]+[.]?[0-9]*)\\))|pop|dump|clear|dup|swap|assert[\\s\\t]*(int8\\(([−]?[0-9]+)\\)|int16\\(([−]?[0-9]+)\\)|float\\(([−]?[0-9]+[.]?[0-9]*)\\)|bigdecimal\\(([−]?[0-9]+[.]?[0-9]*)\\)|int32\\(([−]?[0-9]+)\\)|double\\(([−]?[0-9]+[.]?[0-9]*)\\))|add|sub|mul|div|mod|load[\\s\\t]*(int8\\(([−]?[0-9]+)\\)|int16\\(([−]?[0-9]+)\\)|float\\(([−]?[0-9]+[.]?[0-9]*)\\)|bigdecimal\\(([−]?[0-9]+[.]?[0-9]*)\\)|int32\\(([−]?[0-9]+)\\)|double\\(([−]?[0-9]+[.]?[0-9]*)\\))|(store)[\\s\\t]*(int8\\(([−]?[0-9]+)\\)|int16\\(([−]?[0-9]+)\\)|float\\(([−]?[0-9]+[.]?[0-9]*)\\)|bigdecimal\\(([−]?[0-9]+[.]?[0-9]*)\\)|int32\\(([−]?[0-9]+)\\)|double\\(([−]?[0-9]+[.]?[0-9]*)\\))|print|exit)[\\s\\St]*$");
    std::smatch matches;
    size_t pos;

    file.open(filename.c_str());
    if (file.is_open() == false)
        throw Exception("File does not exist");
    while (file.good() == true && file.eof() != true && line != ";;")
    {
        getline(file, line, '\n');
        if (regex_search(line, matches, regex))
        {
            for (int i = 0; i < matches.size(); i++)
            {
                printf("(%i) => %s\n", i, matches[i]);
            }
            //printf("match: %i\n", matches.size());
        }
        /*if (instruction[0] == ';');
        else if (instruction == "");
        else if ((pos = instruction.find(' ')) != instruction.npos)
        {
            value = instruction.substr(pos + 1, instruction.npos - 1);
            instruction = instruction.substr(0, pos);
            if (value.find('(') == value.npos || value.find(')') == value.npos)
                throw Exception("Invalid value");
            pos = value.find('(');
            type = value.substr(0, pos);
            value = value.substr(pos + 1, value.find(')') - pos - 1);
            if (this->handlers.find(instruction) == this->handlers.end())
                throw Exception("Illegal instruction");
            instructions.push_back({instruction, factory->createOperand(type, value)});
        }
        else
        {
            if (this->handlers.find(instruction) == this->handlers.end())
                throw Exception("Illegal instruction");
            instructions.push_back({instruction, NULL});
        }*/
    }
    file.close();
    delete factory;
    return instructions;
}

void VirtualMachine::fromInput()
{
  std::ofstream outfile (".Input.txt");

  for (std::string line; std::getline(std::cin, line);)
   {
    if (line == ";;")
    {
      outfile.close();
      execute(fromFile(".Input.txt"));
      break;
    }
    else
      outfile << line << std::endl;
}
  outfile.close();
}

void VirtualMachine::execute(std::vector<std::pair<std::string, const IOperand*>> instructions)
{
    for (auto const &instruction : instructions)
        processInstruction((instruction).first, (instruction).second);

    if (instructions.size() != 0)
        if (instructions[instructions.size()].first != "exit")
            throw Exception("Missing exit instruction at the end of program");
}

void VirtualMachine::processInstruction(std::string instruction, IOperand const *operand)
{
    ((this)->*(this->handlers[instruction]))(operand);
}

VirtualMachine::~VirtualMachine()
{

}

void VirtualMachine::exit(IOperand const *operand)
{
    std::exit(0);
}

void VirtualMachine::add(IOperand const *operand)
{
    if (stack.size() < 2)
        throw Exception("Not enough operands in the stack");

    IOperand const *first;
    IOperand const *second;

    first = stack.top();
    stack.pop();
    second = stack.top();
    stack.pop();
    printf("add '%s' + '%s' = '%s'\n", first->toString().c_str(), second->toString().c_str(), (*first + *second)->toString().c_str());
    
    this->push(*first + *second);
}

void VirtualMachine::sub(IOperand const *operand)
{
    if (stack.size() < 2)
        throw Exception("Not enough operands in the stack");

    IOperand const *first;
    IOperand const *second;

    first = stack.top();
    stack.pop();
    second = stack.top();
    stack.pop();
    this->push(*second - *first);
}

void VirtualMachine::div(IOperand const *operand)
{
    if (stack.size() < 2)
        throw Exception("Not enough operands in the stack");

    IOperand const *first;
    IOperand const *second;

    first = stack.top();
    stack.pop();
    second = stack.top();
    stack.pop();
    this->push(*first / *second);
}

void VirtualMachine::mod(IOperand const *operand)
{
    if (stack.size() < 2)
        throw Exception("Not enough operands in the stack");
    IOperand const *first;
    IOperand const *second;

    first = stack.top();
    stack.pop();
    second = stack.top();
    stack.pop();
    this->push(*first % *second);
}

void VirtualMachine::mul(IOperand const *operand)
{
    if (stack.size() < 2)
        throw Exception("Mul on stack with less than two values");
    IOperand const *first;
    IOperand const *second;

    first = stack.top();
    stack.pop();
    second = stack.top();
    stack.pop();
    this->push(*first * *second);
}

void VirtualMachine::push(IOperand const *operand)
{
    stack.push(operand);
}

void VirtualMachine::pop(IOperand const *operand)
{
    if (stack.size() == 0)
        throw Exception("Pop instruction on empty stack");
    stack.pop();
}

void VirtualMachine::dump(IOperand const *o)
{
    if (stack.size() == 0)
        throw Exception("Dump instruction on empty stack");
    std::stack<const IOperand*> substack(stack);
    while (stack.size() != 0)
    {
        std::cout << (stack.top()->toString()) << std::endl;
        stack.pop();
    }
    substack.swap(stack);
}

void VirtualMachine::assert(IOperand const *operand)
{
    const IOperand* target = stack.top();
    if (target->toString() != operand->toString())
        throw Exception("Assert instruction with different value");
    if (target->getType() != operand->getType() - INT8)
        throw Exception("Assert instruction with different type");
}

void VirtualMachine::print(IOperand const *operand)
{
    if (stack.size() == 0)
        throw Exception("Print instruction on empty stack");
    if (stack.top()->getType() != INT8)
        throw Exception("Print instruction on no 8-bit integer");
    std::cout << static_cast<char>(std::stoi(stack.top()->toString())) << std::endl;
}