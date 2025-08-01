// ast/BinaryExpr.hpp
#pragma once
#include "AST.hpp"

class BinaryExpr : public ASTNode {
public:
    BinaryExpr(const std::string& op, ASTNode* left, ASTNode* right)
        : op(op), left(left), right(right) {}
    
    std::string toString() const override {
        return "BinaryExpr(op: " + op + ")";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        return {left, right};
    }

private:
    std::string op;
    ASTNode* left;
    ASTNode* right;
};