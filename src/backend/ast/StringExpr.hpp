// ast/StringExpr.hpp
#pragma once
#include "AST.hpp"

class StringExpr : public ASTNode {
public:
    StringExpr(const std::string& value) : value(value) {}
    
    std::string toString() const override {
        return "StringExpr(value: " + value + ")";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        return {};
    }

private:
    std::string value;
};