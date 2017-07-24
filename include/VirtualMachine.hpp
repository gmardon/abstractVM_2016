//
// VirtualMachine.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Sat Jul 21 1:49:39 PM 2017 guillaume.mardon@epitech.eu
// Last update Mon Jul 24 17:45:47 2017 nathan.bonnet@epitech.eu
//
#ifndef _VIRTUAL_MACHINE_HPP_
#define _VIRTUAL_MACHINE_HPP_
#include "Operand.hpp"
#include "AbstractVM.hpp"
#include "Exception.hpp"
#include "Factory.hpp"

class VirtualMachine
{
    public:
        VirtualMachine();
        ~VirtualMachine();
        std::vector<std::pair<std::string, const IOperand*>> fromFile(std::string file);
        void fromInput();
        void execute(std::vector<std::pair<std::string, const IOperand*>> instructions);
    private:
        void processInstruction(std::string instruction, IOperand const *operand);

        std::stack<IOperand const *> stack;
        std::map<std::string, void (VirtualMachine::*)(IOperand const *)> handlers;

        void exit(IOperand const*);
        void add(IOperand const*);
        void push(IOperand const*);
        void pop(IOperand const*);
        void mul(IOperand const*);
        void dump(IOperand const*);
        void assert(IOperand const*);
        void print(IOperand const*);
        void sub(IOperand const*);
        void mod(IOperand const*);
        void div(IOperand const*);
};
#endif
