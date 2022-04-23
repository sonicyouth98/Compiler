#include "types.h"

#include <memory>
#include <algorithm>


bool operator==(const Type& ls, const Type& rs) {
    if (ls.name == rs.name) {
        return true;
    }
    return false;
}


bool SimpleType::hasVoid() {
    if (*this == *SysType::Void()) {
        return true;
    }
    return false;
}


bool SimpleType::LE(std::shared_ptr<Type>& type2) {
    
}