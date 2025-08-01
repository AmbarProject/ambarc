#pragma once
#include "AST.hpp"

class BreakStmt : public ASTNode {
public:
    std::string toString() const override {
        return "BreakStmt";
    }

    std::vector<ASTNode*> getChildren() const override {
        return {};
    }
};