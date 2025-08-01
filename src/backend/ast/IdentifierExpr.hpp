// ast/IdentifierExpr.hpp
#pragma once
#include "AST.hpp"

class IdentifierExpr : public ASTNode {
public:
    IdentifierExpr(const std::string& name) : name(name) {}
    
    std::string toString() const override {
        return "IdentifierExpr(name: " + name + ")";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        return {};
    }

private:
    std::string name;
};