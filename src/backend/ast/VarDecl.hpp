// ast/VarDecl.hpp
#pragma once
#include "AST.hpp"

class VarDecl : public ASTNode {
public:
    VarDecl(const std::string& name, const std::string& type, ASTNode* init)
        : name(name), type(type), init(init) {}
    
    std::string toString() const override {
        return "VarDecl(name: " + name + ", type: " + type + ")";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        if (init) return {init};
        return {};
    }

private:
    std::string name;
    std::string type;
    ASTNode* init;
};