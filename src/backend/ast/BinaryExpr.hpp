#ifndef BINARYEXPR_H
#define BINARYEXPR_H

#include "AST.hpp"
#include <iostream>
#include <string>

class BinaryExpr : public ASTNode {
public:
    std::string op;
    ASTNode* lhs;
    ASTNode* rhs;

    BinaryExpr(const std::string& o, ASTNode* l, ASTNode* r)
        : op(o), lhs(l), rhs(r) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Binary(" << op << ")\n";
        if (lhs) lhs->print(indent + 2);
        if (rhs) rhs->print(indent + 2);
    }
};

#endif // BINARYEXPR_H
