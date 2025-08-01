// ast/Block.hpp
#pragma once
#include "AST.hpp"
#include <vector>

class Block : public ASTNode {
public:
    void add(ASTNode* stmt) { statements.push_back(stmt); }
    
    std::string toString() const override {
        return "Block";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        return statements;
    }

private:
    std::vector<ASTNode*> statements;
};