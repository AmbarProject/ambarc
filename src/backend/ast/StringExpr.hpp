#ifndef STRING_EXPR_HPP
#define STRING_EXPR_HPP

#include "AST.hpp"
#include <string>
#include <iostream>

class StringExpr : public ASTNode {
public:
    std::string value;

    StringExpr(const std::string& value) : value(value) {}

    void print(int indent = 0) const override {
        std::string spacing(indent, ' ');
        std::cout << spacing << "String(\"" << value << "\")\n";
    }
};

#endif
