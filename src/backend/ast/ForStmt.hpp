#pragma once
#include "AST.hpp"

class Block; // Forward declaration

class ForStmt : public ASTNode {
public:
    ForStmt(ASTNode* init, ASTNode* cond, ASTNode* update, Block* body)
        : init(init), cond(cond), update(update), body(body) {}

    std::string toString() const override {
        return "ForStmt";
    }

    std::vector<ASTNode*> getChildren() const override {
        std::vector<ASTNode*> children;
        if (init) children.push_back(init);
        if (cond) children.push_back(cond);
        if (update) children.push_back(update);
        if (body) children.push_back(body);
        return children;
    }

private:
    ASTNode* init;
    ASTNode* cond;
    ASTNode* update;
    Block* body;
};