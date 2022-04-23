#ifndef _TYPES_H
#define _TYPES_H

#include <memory>
#include <vector>
#include <string>


class Type {
public:
    std::string name;
    Type(const std::string name) : name(name) {

    } 

    virtual bool hasVoid() = 0;

    virtual std::string toString() = 0;

    virtual bool isSimpleType() = 0;

    virtual bool isFunctionType() = 0;

    virtual bool LE(std::shared_ptr<Type>& type2) = 0;

    static std::shared_ptr<Type> getUpperBound(std::shared_ptr<Type>& type1, std::shared_ptr<Type>& type2);
};

bool operator==(const Type& ls, Type& rs);


class SimpleType : public Type {
    std::vector<std::shared_ptr<Type>> upperTypes;
public:
    SimpleType(const std::string& name, std::vector<std::shared_ptr<Type>> upperTypes):
    Type(name), upperTypes(upperTypes) {}
    bool hasVoid() override;
    std::string toString() override {
        std::string upperTypenames = "[";
        for (auto ut : upperTypes) {
            upperTypenames += ut->name + ",";
        }
        upperTypenames += "]";
        return "SimpleType {name: " + this->name + " , upperTypenames : " + upperTypenames + "}";
    } 

    bool isSimpleType() override {
        return true;
    }

    bool isFunctionType() override {
        return false;
    }
    bool LE(std::shared_ptr<Type>& type2) override;
};

class SysType : public Type {
//this is all types father;
public:
    static std::shared_ptr<Type> Any() {
        static std::shared_ptr<Type> type = std::make_shared<SimpleType>("any");
        return type;
    }
//this is some basic type
    static std::shared_ptr<Type> String() {
        auto any = Any();
        std::vector<std::shared_ptr<Type>> vec{any};
        static std::shared_ptr<Type> type = std::make_shared<SimpleType>("string", vec);
        return type;
    }

    static std::shared_ptr<Type> Number() {
        auto any = Any();
        std::vector<std::shared_ptr<Type>> vec{any};
        std::shared_ptr<Type> type = std::make_shared<SimpleType>("NUmber", vec);
        return type;
    }

    static std::shared_ptr<Type> Undefined() {
        std::shared_ptr<Type> type = std::make_shared<SimpleType>("Undefined");
        return type;
    }

    static std::shared_ptr<Type> Null() {
        std::shared_ptr<Type> type = std::make_shared<SimpleType>("Null");
        return type;
    }

    static std::shared_ptr<Type> Boolean() {
        auto any = Any();
        std::vector<std::shared_ptr<Type>> vec{any};
        std::shared_ptr<Type> type = std::make_shared<SimpleType>("Boolean", vec);
        return type;
    }
    //function no return type
    static std::shared_ptr<Type> Void() {
        //auto any = Any();
        //std::vector<std::shared_ptr<Type>> vec{any};
        static std::shared_ptr<Type> type = std::make_shared<SimpleType>("Void");
        return type;
    }

    //this is number son type
    static std::shared_ptr<Type> Integer() {
        //this is inherit number
        auto number = Number();
        std::vector<std::shared_ptr<Type>> vec {number};
        std::shared_ptr<Type> type = std::make_shared<SimpleType>("Integer", vec);
        return type;
    }


    static std::shared_ptr<Type> Decimal() {
        auto decimal = Number();
        std::vector<std::shared_ptr<Type>> vec{decimal};
        std::shared_ptr<Type> type = std::make_shared<SimpleType>("decimal", vec);
        return type;
    }

    static bool isSysType(const std::shared_ptr<Type>& t) {
        return (*t == *SysType::Any() || *t == *SysType::String()||
        *t == *SysType::Boolean() || *t == *SysType::Decimal());
    }
};

class FunctionType : public Type {
public:
    std::shared_ptr<Type> returnType;
    std::vector<std::shared_ptr<Type>> paramTypes;
    static int32_t index;//this is use name function Type;
    FunctionType(std::shared_ptr<Type> returnType = SysType::Void(), const std::vector<std::shared_ptr<Type>> paramTypes = {}
    ,const std::string& name = "") : Type("@function"), paramTypes(paramTypes) {
        if (name != "") {
            this->name += name;
        } else {
            this->name = "@function" + std::to_string(FunctionType::index++);
        }
    }

    bool hasVoid() override{
        return this->returnType->hasVoid();
    }

    bool isSimpleType() override {
        return false;
    }

    bool isFunctionType() override {
        return true;
    }

    std::string toString() override {
        //let all paraments convent string
        std::string paramTypes = "[";
        for (auto ut : this->paramTypes) {
            paramTypes += ut->name + ", ";
        }
        return "FunctionType {name: +" + this->name + ", returnType: " + this->returnType->name + ", paramTypes " + paramTypes; 
    }

    bool LE(std::shared_ptr<Type>& type2) override {
        
    }
};
#endif