#ifndef NUMBEREXPR_H
#define NUMBEREXPR_H

#include "AST.hpp"
#include <iostream>
#include <string>

class NumberExpr : public ASTNode {
public:
    double value;

    NumberExpr(double v) : value(v) {}

    void print(int indent = 0) const override {  // <-- corrigido de double para int
        std::cout << std::string(indent, ' ') << "Number(" << value << ")\n";
    }
};

#endif // NUMBEREXPR_H
