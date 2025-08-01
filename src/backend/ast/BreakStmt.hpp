#ifndef BREAK_STMT_HPP
#define BREAK_STMT_HPP

#include "AST.hpp"
#include <vector>

class BreakStmt : public ASTNode {
public:
    std::string toString() const override {
        return "BreakStmt";
    }

    std::vector<ASTNode*> getChildren() const override {
        return {};  // BreakStmt has no children
    }
};

#endif