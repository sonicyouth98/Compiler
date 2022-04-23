#include "symbol.h"
#include "types.h"

#include <map>
#include <string>

std::string SimKindToString(SymKind kind) {
    static std::map<SymKind, std::string> KindString {
        {SymKind::Variable, "SymKind::Variable"},
        {SymKind::Function, "SymKind::Variable"},
        {SymKind::Class, "SymKind::Class"},
        {SymKind::Interface, "SymKind::Intertace"},
        {SymKind::Parameter, "SymKind::Parameter"},
        {SymKind::Prog, "SymKind::Prog"},
    };

    auto it = KindString.find(kind);
    if (it != KindString.end()) {
        return it->second;
    }

    return "";
}

std::vector<std::shared_ptr<Type>> FUN_println_parms{SysType::String()};

std::shared_ptr<Type> FUN_tick_type = std::make_shared<Type>();
std::map<std::string, std::shared_ptr<FunctionSymbol>> built_ins {
    {"println", FUN_println},
    {"tick", FUN_tick},
    {"integer_to_string", FUN_integer_to_string},
};