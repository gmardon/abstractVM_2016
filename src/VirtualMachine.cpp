//
// VirtualMachine.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Sat Jul 21 1:46:44 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 7:34:12 PM 2017 guillaume.mardon@epitech.eu
//
#include "VirtualMachine.hpp"

VirtualMachine::VirtualMachine() 
{
    this->handlers["exit"] = &VirtualMachine::exit;
    this->handlers["add"] = &VirtualMachine::add;
    this->handlers["push"] = &VirtualMachine::push;
}

void VirtualMachine::fromFile(std::string filename)
{
    std::ifstream file;
    std::string instruction;
    std::string value;
    std::string type;
    size_t pos;

    file.open(filename.c_str());
    if (file.is_open() == false)
        throw Exception("File does not exist");

    while (file.good() == true && file.eof() != true && instruction != ";;")
    {
        getline(file, instruction, '\n');
        if (instruction[0] == ';');
        else if ((pos = instruction.find(' ')) != instruction.npos)
        {
            value = instruction.substr(pos + 1, instruction.npos - 1);
            instruction = instruction.substr(0, pos);
            if (value.find('(') == value.npos || value.find(')') == value.npos)
                throw Exception("Invalid value");
            pos = value.find('(');
            type = value.substr(0, pos);
            value = value.substr(pos + 1, value.find(')') - pos - 1);
            Factory *factory = new Factory(); 
            processInstruction(instruction, factory->createOperand(type, value));
            delete factory;
        }
        else
            processInstruction(instruction, NULL);
    }
    file.close();
    if (instruction != "exit")
        throw Exception("Last instruction should be exit");
}

void VirtualMachine::processInstruction(std::string instruction, IOperand const *operand)
{
    if (this->handlers.find(instruction) == this->handlers.end())
        throw Exception("Instruction '" + instruction  + "' doesn't exist");
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

    op1 = stack.top();
    stack.pop();
    op2 = stack.top();
    stack.pop();
    this->push(*op1 + *op2);
}

void VirtualMachine::push(IOperand const *operand)
{
    stack.push(operand);
}