#ifndef BOOL_EXPR_HPP
#define BOOL_EXPR_HPP

#include "AST.hpp"
#include <iostream>

class BoolExpr : public ASTNode {
public:
    bool value;

    BoolExpr(bool value) : value(value) {}

    void print(int indent = 0) const override {
        std::string spacing(indent, ' ');
        std::cout << spacing << "Bool(" << (value ? "true" : "false") << ")\n";
    }
};

#endif
