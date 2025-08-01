// ast/FunctionDecl.hpp
#ifndef FUNCTION_DECL_HPP
#define FUNCTION_DECL_HPP

#include "AST.hpp"
#include "Block.hpp"
#include <string>
#include <vector>

class FunctionDecl : public ASTNode {
public:
    FunctionDecl(const std::string& name, 
                const std::string& returnType,
                const std::vector<std::pair<std::string, std::string>>& params,
                Block* body)
        : name(name), returnType(returnType), params(params), body(body) {}

    ~FunctionDecl() override {
        delete body;
    }

    std::string toString() const override {
        return "FunctionDecl(" + name + "): " + returnType;
    }

    std::vector<ASTNode*> getChildren() const override {
        std::vector<ASTNode*> children;
        if (body) children.push_back(body);
        return children;
    }

private:
    std::string name;
    std::string returnType;
    std::vector<std::pair<std::string, std::string>> params;
    Block* body;
};

#endif