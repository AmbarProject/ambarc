#ifndef STRING_EXPR_HPP
#define STRING_EXPR_HPP

#include "AST.hpp"
#include <string>

class StringExpr : public ASTNode {
public:
    std::string value;

    StringExpr(const std::string& val) : value(val) {}

    void print(int indent = 0) const override {
        std::string indentStr(indent, ' ');
        std::cout << indentStr << "STRING: \"" << value << "\"" << std::endl;
    }
};

#endif
