#ifndef ASSIGNSTMT_HPP
#define ASSIGNSTMT_HPP

#include "AST.hpp"
#include <iostream>
#include <string>

class AssignStmt : public ASTNode {
public:
    std::string identifier;
    ASTNode* value;

    AssignStmt(const std::string& id, ASTNode* val)
        : identifier(id), value(val) {}

    void print(int indent = 0) const override {
        std::string space(indent, ' ');
        std::cout << space << "AssignStmt(" << identifier << ")\n";
        if (value)
            value->print(indent + 2);
    }

    ~AssignStmt() override {
        delete value;
    }
};

#endif // ASSIGNSTMT_HPP
