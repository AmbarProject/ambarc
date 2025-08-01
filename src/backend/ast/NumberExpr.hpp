// ast/NumberExpr.hpp
#pragma once
#include "AST.hpp"
#include <string>
#include <variant>

class NumberExpr : public ASTNode {
public:
    NumberExpr(int value) : value(value), isFloat(false) {}
    NumberExpr(float value) : value(value), isFloat(true) {}
    
    std::string toString() const override {
        if (isFloat) {
            char buffer[32];
            snprintf(buffer, sizeof(buffer), "%.6f", std::get<float>(value));
            // Remove zeros desnecessários
            std::string s(buffer);
            s.erase(s.find_last_not_of('0') + 1, std::string::npos);
            if (s.back() == '.') s.push_back('0');
            return "NumberExpr(value: " + s + ")";
        } else {
            return "NumberExpr(value: " + std::to_string(std::get<int>(value)) + ")";
        }
    }
    
    std::vector<ASTNode*> getChildren() const override {
        return {};
    }

private:
    std::variant<int, float> value;
    bool isFloat;
};