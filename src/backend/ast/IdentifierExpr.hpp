#ifndef IDENTIFIER_EXPR_HPP
#define IDENTIFIER_EXPR_HPP

#include "AST.hpp"
#include <string>
#include <iostream>

class IdentifierExpr : public ASTNode {
public:
    std::string name;

    IdentifierExpr(const std::string& name) : name(name) {}

    void print(int indent = 0) const override {
        std::string spacing(indent, ' ');
        std::cout << spacing << "Identifier(" << name << ")\n";
    }
};

#endif
