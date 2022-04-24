#include "scanner.h"
#include <unordered_map>

std::unordered_map<TokenKind, std::string> tokenString {

};

std::unordered_map<Op, std::string> OpToString {

};

std::unordered_map<std::string, KeyWordKind> Scanner :: keywordMap = {

};
std::string toString(TokenKind kind) {
    auto it = tokenString.find(kind);
    if (it != tokenString.end()) {
        return it->second;
    }
    return "Unknown Kind?";
}

std::string toString(Op op) {
    auto it = OpToString.find(op);
    if (it != OpToString.end()) {
        return it->second;
    }

    return "UNKNOWN OP?";
}

