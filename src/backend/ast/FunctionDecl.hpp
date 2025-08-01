#pragma once
#include "AST.hpp"
#include <vector>
#include <string>
#include <utility>

class Block; // Forward declaration

class FunctionDecl : public ASTNode {
public:
    FunctionDecl(const std::string& name, 
                const std::string& returnType,
                const std::vector<std::pair<std::string, std::string>>& params,
                Block* body)
        : name(name), returnType(returnType), params(params), body(body) {}

    std::string toString() const override {
        return "FunctionDecl(name: " + name + ", returns: " + returnType + ")";
    }

    std::vector<ASTNode*> getChildren() const override {
        std::vector<ASTNode*> children;
        if (body) {
            children.push_back(body);
        }
        return children;
    }

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << toString() << std::endl;
        
        // Print parameters
        printIndent(indent + 1);
        std::cout << "Params:" << std::endl;
        for (const auto& param : params) {
            printIndent(indent + 2);
            std::cout << param.first << ": " << param.second << std::endl;
        }
        
        // Print body
        if (body) {
            body->print(indent + 1);
        }
    }

private:
    std::string name;
    std::string returnType;
    std::vector<std::pair<std::string, std::string>> params;
    Block* body;

protected:
    void printIndent(int indent) const {
        for (int i = 0; i < indent; ++i) std::cout << "  ";
    }
};