#ifndef NUMBEREXPR_H
#define NUMBEREXPR_H

#include "AST.hpp"

class NumberExpr : public ASTNode {
    public:
        int value;
        NumberExpr(int v) : value(v) {}
        void print(int indent = 0) const override {
            std::cout << std::string(indent, ' ') << "Number(" << value << ")\n";
        }
    };

#endif
