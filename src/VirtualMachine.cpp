//
// VirtualMachine.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Sat Jul 21 1:46:44 PM 2017 guillaume.mardon@epitech.eu
// Last update Sun Jul 22 3:14:09 PM 2017 guillaume.mardon@epitech.eu
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

    first = stack.top();
    stack.pop();
    second = stack.top();
    stack.pop();
    this->push(*first + *second);
}

void VirtualMachine::mul(IOperand const *operand)
{
    if (stack.size() < 2)
        throw Exception("Not enough operands in the stack");
    
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
    stack.pop();
}

void VirtualMachine::dump(IOperand const *o)
{
    if (stack.size() == 0)
        throw Exception("Dump instruction on empty stack");
    std::stack<const IOperand*> substack;
    while (stack.size() != 0)
    {
        substack.push(stack.top());
        std::cout << (substack.top()->toString()) << std::endl;
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