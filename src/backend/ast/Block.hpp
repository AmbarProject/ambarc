#pragma once
#include "AST.hpp"
#include <vector>

class Block : public ASTNode {
public:
    std::vector<ASTNode*> statements;

    void add(ASTNode* stmt) {
        if (stmt) statements.push_back(stmt);
    }

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Block" << std::endl;
        for (auto stmt : statements) {
            stmt->print(indent + 2);
        }
    }
};
