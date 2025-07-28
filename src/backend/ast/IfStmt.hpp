#pragma once
#include "AST.hpp"

class IfStmt : public ASTNode {
public:
    ASTNode* condition;
    ASTNode* thenBlock;
    ASTNode* elseBlock;

    IfStmt(ASTNode* cond, ASTNode* thenBlk, ASTNode* elseBlk = nullptr)
        : condition(cond), thenBlock(thenBlk), elseBlock(elseBlk) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "IfStmt" << std::endl;
        if (condition) condition->print(indent + 2);
        if (thenBlock) thenBlock->print(indent + 2);
        if (elseBlock) {
            printIndent(indent);
            std::cout << "Else:" << std::endl;
            elseBlock->print(indent + 2);
        }
    }
};
