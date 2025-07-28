// AST.hpp
#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>

class ASTNode {
    public:
        virtual ~ASTNode() = default;
        virtual void print(int indent = 0) const = 0;
    };

#endif
