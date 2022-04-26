#ifndef _ERROR_H
#define _ERROR_H

#include <stdint.h>
#include <string>
struct Position {
    uint32_t line;
    uint32_t col = 1;
    uint32_t begin = 1;
    uint32_t end = 1;

    Position() {}

    Position(uint32_t line, uint32_t col, 
    uint32_t begin, uint32_t end) : line(line), col(col), begin(begin), end(end){}
    std::string toString() {
        return "(ln" + std::to_string(this->line) + ", col: " + std::to_string(this->col) +
        ", Pos: " + std::to_string(this->begin) + ")";
    }

    Position(const Position& other) {
        this->begin = other.begin;
        this->end = other.end;
        this->line = other.line;
        this->col = other.col;
    }
};

class CompilerError {
    std::string message;
    const Position beginPos;
    bool isWarning{false};
public:
    CompilerError(const std::string message, Position& beginpos,
    bool isWarning = false) : message(message), beginPos(beginPos) {

    }
};
#endif