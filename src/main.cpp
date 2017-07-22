//
// main.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Sat Jul 21 1:52:09 PM 2017 guillaume.mardon@epitech.eu
// Last update Sun Jul 22 5:10:06 PM 2017 guillaume.mardon@epitech.eu
//
#include "AbstractVM.hpp"
#include "VirtualMachine.hpp"

int main(int argc, char *argv[])
{
    //try {
        VirtualMachine *vm = new VirtualMachine();
        if (argc == 2)
            vm->fromFile(argv[1]);
    //} catch (Exception &ex) {
    //    printf("%s\n", ex.what());
    //}
    
}