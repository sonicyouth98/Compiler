#include "error.h"

#include <stdint.h>
#include <vector>
#include <string>
#include <any>
#include <unordered_map>
#include <list>

enum class TokenKind {};

//sperator

enum class Seperator{
    
};


enum class Op {

};

enum class KeyWordKind {
//this is mu language keyword
};


inline std::string toString(uint32_t obj) {
    return std::to_string(obj);
}

struct Token {
    TokenKind kind;
    std::string text;
    Position pos;
    std::any code;

};

class CharStream {
public:
    std::string data;
    uint32_t pos = 0;
    uint32_t line = 0;
    uint32_t col = 0;

    CharStream(const std::string& data) : data(data) {

    }

    //begin 
    char peak() {
        return this->data[pos];
    }

    char next() {
        auto ch = this->data[pos++];
        //we need 
        if (ch == '\n') {

        }

    }

    bool eof() {
        return this->peak() == '\0';
    }

    Position getPos() {
        //return Position(this->)
    }
};
class Scanner {
    std::list<Token> token;
    CharStream& stream;

public:
    Scanner(CharStream& stream) : stream(stream) {}

    Token next() {
        
    }
};
