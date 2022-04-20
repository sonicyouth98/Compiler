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

    virtual bool isFUnctionTYpe() = 0;

    virtual bool LE(std::shared_ptr<Type>& type2) = 0;

    
};

bool operator==(const std::shared_ptr<Type>& ls, const std::shared_ptr<Type>& rs);


class SimleType : public Type {
    std::vector<std::shared_ptr<Type>> upperTypes;
public:
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
};
#endif