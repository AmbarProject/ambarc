#ifndef VARDECL_HPP
#define VARDECL_HPP

#include "AST.hpp"
#include <string>

class VarDecl : public ASTNode {
public:
    std::string name;
    std::string type;
    ASTNode* value;

    VarDecl(const std::string& name, const std::string& type, ASTNode* value)
        : name(name), type(type), value(value) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "VarDecl(" << name << ": " << type << ")\n";
        if (value) {
            value->print(indent + 2);
        } else {
            std::cout << std::string(indent + 2, ' ') << "(no init)\n";
        }
    }
};

#endif
