#pragma once
#include "AST.hpp"

class ContinueStmt : public ASTNode {
public:
    std::string toString() const override {
        return "ContinueStmt";
    }

    std::vector<ASTNode*> getChildren() const override {
        return {};
    }
};