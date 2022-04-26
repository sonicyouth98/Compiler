#include "error.h"

#include <iostream>
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
    OpenBracket = 0, //[
    CloseBracket , //]
    OpenParen , //(
    CloseParen, //)
    OpenBrace, //{
    CloseBrace,  //}
    Colon,  //:
    SemiColon //;
};


enum class Op {
    QuestionMark = 100,// ?
    Ellipsis, //...
    DOt, //.
    Comma, //,
    At, //@

    RightShiftArithmetic, //>>
    LeftShiftArithmetic,//<<
    RightShiftLogical, //>>>
    IdentityNotEquals,//

    BitNot, //~
    BitAdd, //&
    BitXor, //^
    BitOr, //|

    Not, //!
    And, //&&
    Or, //||

    Assign, // =
    MultiplayAssign,//*=
    DivideAssign, // /=
    ModuleAssign, // %=
    PlusAssign, //+=
    MinusAssign, // -=
    LeftShiftArithmeticAssign, //<<=
    RightShiftArithmeticAssign, //>>=
    RightShiftLogicalAssign, // >>>=
    BitAddAssign, //&=
    BitXorAssign, //^=
    BitOrAssign, // |=

    ARROW, //=>

    Inc, //++
    Dec, //--

    Plus, //+
    Minus, //-
    Multiply, //*
    Divide ,// /
    Modules, // %

    EQ,//==
    NE, //!=
    G, // >
    GE, // >=
    L, //<
    LE,
};

//this is bijiao operator

enum class KeyWordKind {
//this is mu language keyword

    Function = 200,
    Class,
    Break,
    Delete,
    Return,
    Case,
    Do,
    If,
    Switch,
    Var,
    Catch,
    Else,
    In,
    This,
    Void,
    Continue,
    False,
    Instanceof,
    Throw,
    While,
    Debugger,
    Finally,
    New,
    True,
    With,
    Default,
    For,
    NUll,
    Try,
    Typeof,
    Implements,
    Let,
    Private,
    Public,
    Yield,
    Interface,
    Package,
    Protected,
    Static,
    Number,
    String,
    Boolean,
    Any,
    Symbol,
    Underfined,
};



//this is overloadfunction in the scanner.cpp
inline std::string toString(uint32_t obj) {
    return std::to_string(obj);
}



struct Token {
    TokenKind kind;
    std::string text;
    Position pos;
    std::any code;//this is code container op Seperator keyword
    Token(TokenKind kind, const std::string& text, const Position& pos, std::any code = std::any()) : kind(kind), text(text), pos(pos), code(code){}

    Token(TokenKind kind, char c, const Position& pos, std::any code = std::any()) : kind(kind), text(std::string(1, c)), pos(pos), code(code){

    }
    std::string toString() {

    }
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
    Position lastPos{0, 0, 0, 0};
    static std::unordered_map<std::string, KeyWordKind> keywordMap;
public:
    Scanner(CharStream& stream) : stream(stream) {}

    Token next() {
        
    }

private:
    Token getAToken() {
        this->skipWhiteSpaces();
        //this position
        auto pos = this->stream.getPos();
        if (this->stream.eof()) {
            return Token(TokenKind::Eof, "Eof", pos);
        } else {
            auto ch = this->stream.peak();
            if (this->isLetter(ch) || ch == '_') {
                return parseIdentifer();
            } else if(ch == '"') {
                return parseStringLiteral();
            } else if (ch == '(') {
                this->stream.next();
                //return operator
                return Token(TokenKind::Seperator, ch, pos, Seperator::OpenParen);
            } else if (ch == ')') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Seperator::CloseParen);
            } else if (ch == '{') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Seperator::OpenBrace);
            } else if (ch == '}') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Seperator::CloseBrace);
            } else if (ch == '[') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Seperator::OpenBracket);
            } else if (ch == ']') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Seperator::CloseBracket);
            } else if (ch == ':') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Seperator::Colon);
            } else if (ch == ';') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Seperator::SemiColon);
            } else if (ch == ',') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Op::Comma);
            } else if (ch == '?') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Op::QuestionMark);
            } else if (ch == '@') {
                this->stream.next();
                return Token(TokenKind::Seperator, ch, pos, Op::At);
            } 
            //parse IntegerLiteral
            //DeceimalLiteral: IntegerLiteral '.' [0~9]*
            //  | '.'
            //
            //IntegerLiteral '0' | [1-9] [0-9]*;
            else if (this->isDigit(ch)) {
                this->stream.next();
                auto ch1 = this->stream.peak();
                std::string literal = "";
                if (ch == '0') {
                    if (!(ch1 >= '1' && ch1 <= '9')) {
                        literal += "0";
                    } else {
                        //this is not follower number
                        std::cout << "O can not be followed by other digit now, at line" + toString(this->stream.line) + "col" + toString(this->stream.col) << std::endl;
                        this->stream.next();
                        return this->getAToken();
                    }
                } else if (ch >= '1' && ch <= '9') {
                    literal += ch;
                    //start check ch1
                    while (this->isDigit(ch1)) {
                        ch = this->stream.next();
                        literal += ch;
                        ch1 = this->stream.peak();          
                    }
                }

                if (ch1 == '.') {
                    literal += '.';
                    this->stream.next();

                } 
                else {
                    //return 
                }
            }
        }
    }
    void skipSingleLineComment() {
        this->stream.next();
        while (this->stream.peak() != '\n' && !this->stream.eof()) {
            this->stream.next();
        }
    }

    void skipMultipleLineComments() {
        this->stream.next();

        if (!this->stream.eof()) {

            return ;
        }

        std::cout << ("Failed to matching */ for multiple line comments at :") + toString(this->stream.line) + "col" + toString(this->stream.col) << std::endl;
    }
    void skipWhiteSpaces() {
        while (this->isWhiteSpace(this->stream.peak()))
        {
            this->stream.next();
        }
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
