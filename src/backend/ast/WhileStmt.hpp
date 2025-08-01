// ast/WhileStmt.hpp
#pragma once
#include "AST.hpp"

class WhileStmt : public ASTNode {
public:
    WhileStmt(ASTNode* cond, ASTNode* body)
        : cond(cond), body(body) {}
    
    std::string toString() const override {
        return "WhileStmt";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        return {cond, body};
    }

private:
    ASTNode* cond;
    ASTNode* body;
};