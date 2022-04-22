#include "error.h"

#include <stdint.h>
#include <vector>
#include <string>
#include <any>
#include <unordered_map>
#include <list>

enum class TokenKind {KeyWord, Identifier, StringLiteral, IntegerLiteral, DeceimalLiteral,
Seperator, Operator, Eof};

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
    std::any code;//this is code container op Seperator keyword
    Token(TokenKind kind, const std::string& text, const Position& pos, std::any code = std::any()) {}
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
private:
    std::list<Token> token;
    CharStream& stream;

public:
    Scanner(CharStream& stream) : stream(stream) {}

    Token next() {
        
    }

private:
    Token getToken() {
        this->skipWhiteSpaces();
        //this position
        auto pos = this->stream.getPos();
        if (this->stream.eof()) {
            return Token(TokenKind::Eof, "Eof", pos);
        } else {
            auto ch = this->stream.peak();
            if (this->isLetter(ch) || ch == '_') {

            } else if(ch == '"') {

            } else if (ch == '(') {
                this->stream.next();
                //return operator
                //return Token()
            } else if (ch == ')') {
                this->stream.next();
            } else if (ch == '{') {
                this->stream.next();
            } 
        }
    }
    void skipSingleLineComment() {

    }

    void skipMultipleLineComments() {

    }
    void skipWhiteSpaces() {

    }
    Token parseStringLiteral() {

    }
    Token parseIdentifer() {
        
        //this we need the second char

    }
    // from charstream a new Token
   inline bool isLetterDigitOrUnderScore(char ch) {
       return true;
   }
   inline bool isLetter(char ch) {
        return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
    }

   inline bool isDigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }

    inline bool isWhiteSpace(char ch) {
        return (ch == ' ' || ch == '\n' || ch == '\t');
    }
};
