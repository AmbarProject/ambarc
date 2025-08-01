// ast/ReturnStmt.hpp
#pragma once
#include "AST.hpp"

class ReturnStmt : public ASTNode {
public:
    ReturnStmt(ASTNode* expr = nullptr) : expr(expr) {}
    
    std::string toString() const override {
        return "ReturnStmt";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        if (expr) return {expr};
        return {};
    }

private:
    ASTNode* expr;
};