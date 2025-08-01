// ast/AssignStmt.hpp
#pragma once
#include "AST.hpp"

class AssignStmt : public ASTNode {
public:
    AssignStmt(const std::string& name, ASTNode* expr)
        : name(name), expr(expr) {}
    
    std::string toString() const override {
        return "AssignStmt(to: " + name + ")";
    }
    
    std::vector<ASTNode*> getChildren() const override {
        return {expr};
    }

private:
    std::string name;
    ASTNode* expr;
};