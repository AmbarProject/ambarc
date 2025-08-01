// ast/Program.hpp
#pragma once
#include "AST.hpp"
#include <vector>

class Program : public ASTNode {
public:
    void add(ASTNode* decl) { declarations.push_back(decl); }
    
    std::string toString() const override {
        return "Program";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        return declarations;
    }

private:
    std::vector<ASTNode*> declarations;
};