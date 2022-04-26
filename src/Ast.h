#ifndef _AST_H
#define _AST_H

#include "scanner.h"
#include "error.h"


#include <string>
#include <unordered_map>
#include <any>
#include <memory>
#include <stdint.h>
#include <sstream>
//this is programming ast node

class AstNode;
class ErrorStmt;
class ErrorExp;
class Variable;
class IntegerLiteral;
class ParameterList;
class VariableStatement;
class ExpressionStatement;
class FunctionCall
class Block;
class Prog;
class CallSignature;
class FunctionDecl;
class ReturnStatement;
class Binary;

class AstVisitor {
public:
    virtual std::any visit(AstNode& node, std::string additional = "") ;
    virtual std::any visitParameter(ParameterList& paramlist, std::string additional = "");
    virtual std::any visitVariableDecl(Variable& variable, std::string additional = "");
    virtual std::any visitVariableStatement(VariableStatement& variablestatement, std::string additional = "");
};

class AstNode {
public:
    Position beginpos;
    Position endpos;
    bool isErrorNode {false};
    AstNode(Position beginpos, Position endpos, bool isErrorNode) : beginpos(beginpos), endpos(endpos), isErrorNode(isErrorNode){}

    virtual std::any accept(AstVisitor& visitor, std::string additional) = 0;
};

class Statement : public AstNode {
public:
    std::string name;
    Statement(Position beginpos, Position endpos, bool isErroNode) : AstNode(beginpos, endpos, isErroNode) , name(name){}
};

class Decl : public AstNode {

};

class ErrorStmt : public AstNode {

};

class Expression : public AstNode {

};

class ErrorExp : public Expression {

};

class ExpressionStament : public Statement {
 //this is add ; int Expression


};

class IntegerLiteral : public Expression {

};



class AstDumper : public AstVisitor {
    std::stringstream ss;
public:
    std::any visit() override {
        
    }
    std::string toString() {

    }
};
#endif