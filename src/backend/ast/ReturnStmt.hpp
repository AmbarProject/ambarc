#pragma once
#include "AST.hpp"

class ReturnStmt : public ASTNode {
public:
    ASTNode* value;

    ReturnStmt(ASTNode* value = nullptr) : value(value) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "ReturnStmt" << std::endl;
        if (value) value->print(indent + 2);
    }
};
