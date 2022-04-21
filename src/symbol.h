#ifndef _SYMBOL_H
#define _SYMBOL_H

#include "types.h"
#include "error.h"

#include <any>
#include <vector>

enum class SymKind {Variable, Function, Class, Interface, Parameter, Prog};

std::string SimKindToString();

class ValSymbol;
class FunctionSymbol;
class SymbolVisitor {
public:
    virtual std::any visitVarSymbol(ValSymbol& sym, std::string additional);
    virtual std::any visitFunctionSymbol(FunctionSymbol& sym, std::string additional);
};

class Symbol {
public:
    std::string name;
    SymKind kind;
    std::shared_ptr<Type> theType;

    Symbol(const std::string& name, SymKind kind, std::shared_ptr<Type>& theType):
    name(name), kind(kind), theType(theType) {

    }

    //this is virtual function for son class
    virtual std::any accept(SymbolVisitor& vistor, std::string additional) = 0;
};

class VarSymbol : public Symbol {
public:
    VarSymbol(const std::string &name, SymKind kind, std::shared_ptr<Type>& theType) :
    Symbol(name, SymKind::Variable, theType){

    }
    std::any accept(SymbolVisitor& visitor, std::string additional) override {
            return visitor.visitVarSymbol(*this, additional);
    }

};


class FunctionDecl;

class FunctionSymbol : public Symbol {
public:
    std::vector<std::shared_ptr<Symbol>> vars;

    uint32_t opStackSize = 10;

    
};

class SymbolDumper : public SymbolVisitor{
public:
    std::any visit(Symbol& sym, std::string additional) {
        return sym.accept(*this, additional);
    }

    //print message


};
#endif