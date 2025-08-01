// ast/IfStmt.hpp
#pragma once
#include "AST.hpp"

class IfStmt : public ASTNode {
public:
    IfStmt(ASTNode* cond, ASTNode* thenBlock, ASTNode* elseBlock = nullptr)
        : cond(cond), thenBlock(thenBlock), elseBlock(elseBlock) {}
    
    std::string toString() const override {
        return "IfStmt";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        std::vector<ASTNode*> children = {cond, thenBlock};
        if (elseBlock) children.push_back(elseBlock);
        return children;
    }

private:
    ASTNode* cond;
    ASTNode* thenBlock;
    ASTNode* elseBlock;
};