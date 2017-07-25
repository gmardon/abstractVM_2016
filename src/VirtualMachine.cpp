//
// VirtualMachine.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Sat Jul 21 1:46:44 PM 2017 guillaume.mardon@epitech.eu
// Last update Wed Jul 25 10:25:48 AM 2017 guillaume.mardon@epitech.eu
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
    this->handlers["store"] = &VirtualMachine::store;
    this->handlers["load"] = &VirtualMachine::load;
}

std::vector<std::pair<std::string, const IOperand*>> VirtualMachine::fromFile(std::string filename)
{
    Factory *factory = new Factory();
    std::ifstream file;
    std::string line;
    std::string value;
    std::string type;
    std::string instruction;
    std::vector<std::pair<std::string, const IOperand*>> instructions;
    std::regex regex("^(push|pop|dump|clear|dup|swap|assert|add|sub|mul|div|mod|load|store|print|exit)[\\s\\t]*(int8|int16|int32|float|double|bigdecimal)?\\(?([−]?[0-9]+[.]?[0-9]*)?\\)?");    
    std::smatch matches;
    size_t pos;

    file.open(filename.c_str());
    if (file.is_open() == false)
        throw Exception("File does not exist");
    while (file.good() == true && file.eof() != true && line != ";;")
    {
        getline(file, line, '\n');
        trim(line);
        if (regex_search(line, matches, regex))
        {
            instruction = matches[1];
            if (this->handlers.find(instruction) == this->handlers.end())
                throw Exception("Illegal instruction");
            if (matches[2] != "") // instruction with operand
                instructions.push_back({instruction, factory->createOperand(matches[2], matches[3])});
            else
                 instructions.push_back({instruction, NULL});
        }
        else if (line[0] == ';' || line == "");
        else
            throw Exception("Illegal instruction");
    }
    file.close();
    delete factory;
    return instructions;
}

void VirtualMachine::fromInput()
{
    std::string file = ".input.txt";
    std::ofstream outfile (file);
    for (std::string line; std::getline(std::cin, line);)
    {
        if (line == ";;")
        {
        outfile.close();
        execute(fromFile(file));
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
    this->push(*second / *first);
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
    this->push(*second % *first);
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

void VirtualMachine::clear(IOperand const *operand) 
{ 
    stack = std::stack<IOperand const *>(); 
}

void VirtualMachine::store(IOperand const *operand) 
{ 
    int reg = atoi(operand->toString().c_str());
    if (reg >= 0 && reg <= 15)
    {
        registers[reg] = stack.top();
        stack.pop();
    }
    else
        throw Exception("Register must be between 0 and 15 !");
    stack = std::stack<IOperand const *>(); 
}

void VirtualMachine::load(IOperand const *operand) 
{ 
    int reg = atoi(operand->toString().c_str());
    if (registers[reg] != NULL)
        stack.push(registers[reg]);
    else
        throw Exception("Load an register empty cell");
}