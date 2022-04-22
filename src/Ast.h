#ifndef _AST_H
#define _AST_H

#include "scanner.h"
#include "error.h"


#include <string>
#include <unordered_map>
#include <any>
#include <memory>
#include <stdint.h>

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


    virtual std::any accept(AstVisitor& visitor, std::string additional) = 0;
};

class Statement : public AstNode {
public:
    Statement(Position beginpos, )
};
#endif