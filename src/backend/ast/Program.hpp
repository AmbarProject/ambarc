#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "AST.hpp"
#include <vector>
#include <memory>

class Program : public ASTNode {
public:
    std::vector<ASTNode*> declarations;

    void add(ASTNode* decl) {
        if (decl) declarations.push_back(decl);
    }

    void print(int indent = 0) const override {
        std::string space(indent, ' ');
        std::cout << space << "Program\n";
        for (const auto& decl : declarations) {
            if (decl) decl->print(indent + 2);
        }
    }

    ~Program() {
        for (auto* node : declarations)
            delete node;
    }
};

#endif
