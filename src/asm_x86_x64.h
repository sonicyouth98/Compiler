#ifndef _ASM_X86_X64_H
#define _ASM_X86_X64_H
#include "scanner.h"
#include "error.h"
#include "types.h"
#include "scope.h"
#include "Ast.h"


#include <set>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <any>
#include <stdint.h>
#include <typeinfo>

enum class AsmOpCode {
//this asm code

};

enum class OprandKind{

};

std::string toString(AsmOpCode op);
std::string toString(OprandKind kind);


class OpCodeHelper {
public:
    static bool isReturn(AsmOpCode op) {
        //return whether return asmcode
    }

    static bool isJump(AsmOpCode op) {
        //return whether return asmcode
    }
};

class Oprand {
public:

};

class Inst {
public:
    AsmOpCode op;

};


class BasicBlock {
public:

};


class AsmModule {
public:
    //every function reperenst inst array
    std::map<std::string, std::vector<std::shared_ptr<BasicBlock>>> fun2Code;
    std::map<std::string, uint32_t> numPars;//the function paraments numbers
    std::map<std::string, uint32_t> numVars;//the function var numbers;

    std::map<std::string, bool> isLeafFunction;

    //
    std::vector<std::string> stringConsts;

    //input asm 
    std::string toString() {
        std::string str = "";

        return str;
    }
};

class AsmGenerator : AstVisitor {
public:
    
};
#endif