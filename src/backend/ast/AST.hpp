// ast/AST.hpp
#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    
    virtual std::string toString() const = 0;
    virtual std::vector<ASTNode*> getChildren() const = 0;
    virtual void print(int indent = 0) const {
        for (int i = 0; i < indent; ++i) std::cout << "  ";
        std::cout << toString() << std::endl;
        for (auto child : getChildren()) {
            if (child) child->print(indent + 1);
        }
    }
};