// ast/BoolExpr.hpp
#pragma once
#include "AST.hpp"

class BoolExpr : public ASTNode {
public:
    BoolExpr(bool value) : value(value) {}
    
    std::string toString() const override {
        return "BoolExpr(value: " + std::string(value ? "true" : "false") + ")";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        return {};
    }

private:
    bool value;
};