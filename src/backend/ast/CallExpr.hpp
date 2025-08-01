#pragma once
#include "AST.hpp"
#include <vector>
#include <string>

class CallExpr : public ASTNode {
public:
    CallExpr(const std::string& funcName, const std::vector<ASTNode*>& args)
        : funcName(funcName), args(args) {}

    std::string toString() const override {
        return "CallExpr(func: " + funcName + ")";
    }

    std::vector<ASTNode*> getChildren() const override {
        return args;
    }

private:
    std::string funcName;
    std::vector<ASTNode*> args;
};