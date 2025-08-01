#ifndef CALL_EXPR_HPP
#define CALL_EXPR_HPP

#include "AST.hpp"
#include <string>
#include <vector>

class CallExpr : public ASTNode {
    std::string callee;
    std::vector<ASTNode*> arguments;

public:
    CallExpr(std::string funcName, std::vector<ASTNode*> args)
        : callee(std::move(funcName)), arguments(std::move(args)) {}

    ~CallExpr() override {
        for (auto arg : arguments) {
            delete arg;
        }
    }

    std::string toString() const override {
        return "CallExpr(callee: " + callee + ")";
    }

    std::vector<ASTNode*> getChildren() const override {
        return arguments;
    }

    const std::string& getCallee() const { return callee; }
    const std::vector<ASTNode*>& getArguments() const { return arguments; }
};

#endif