#pragma once
#include "AST.hpp"

class WhileStmt : public ASTNode {
public:
    ASTNode* condition;
    ASTNode* body;

    WhileStmt(ASTNode* cond, ASTNode* body) : condition(cond), body(body) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "WhileStmt" << std::endl;
        if (condition) condition->print(indent + 2);
        if (body) body->print(indent + 2);
    }
};
