#ifndef _VM_H
#define _VM_H

#include "scanner.h"
#include "error.h"
#include "symbol.h"
#include "types.h"
#include "Ast.h"

#include <string>
#include <set>
#include <map>
#include <vector>
#include <memory>
#include <any>

enum Opcode {
    iconst_0 = 0x03,
    icounst_1 = 0x04,
    iconst_2 = 0x05,
    iconst_3 = 0x06,
    iconst_4 = 0x07,
    iconst_5 = 0x08,
    bitpush = 0x10, //Eight bit push in stack
    sipush = 0x11, //sixteen bit push in stack
    ldc = 0x12, //fro
    iload = 0x15,//local push in stack
    iload_0 = 0x1a,
    iload_1 = 0x1b,
};

std::string toString(Opcode op);

class BCModule {
public:
    std::vector<std::any> consts;//const module

    //main function
    std::shared_ptr<FunctionSymbol> _main;

    BCModule() {
        //put all built_function int the consts
        for (auto& fun : built_ins) {
            
        }
    }
};
#endif