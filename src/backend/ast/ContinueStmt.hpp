#ifndef CONTINUE_STMT_HPP
#define CONTINUE_STMT_HPP

#include "AST.hpp"

class ContinueStmt : public ASTNode {
public:
    ContinueStmt() = default;

    std::string toString() const override {
        return "ContinueStmt";
    }

    std::vector<ASTNode*> getChildren() const override {
        return {};  // No children
    }
};

#endif