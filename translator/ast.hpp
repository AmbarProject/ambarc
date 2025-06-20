#pragma once
#include <string>
#include <memory>

struct Expr {
    virtual std::string toC() const = 0;
    virtual ~Expr() = default;
};

struct ConstExpr : Expr {
    int value;
    ConstExpr(int v) : value(v) {}
    std::string toC() const override {
        return std::to_string(value);
    }
};

struct VarExpr : Expr {
    std::string name;
    VarExpr(std::string n) : name(std::move(n)) {}
    std::string toC() const override {
        return name;
    }
};

struct BinOpExpr : Expr {
    std::string op;
    std::shared_ptr<Expr> lhs, rhs;
    BinOpExpr(std::string o, std::shared_ptr<Expr> l, std::shared_ptr<Expr> r)
        : op(std::move(o)), lhs(std::move(l)), rhs(std::move(r)) {}
    std::string toC() const override {
        return "(" + lhs->toC() + " " + op + " " + rhs->toC() + ")";
    }
};

struct DeclStmt {
    std::string name, type;
    std::shared_ptr<Expr> value;
    std::string toC() const {
        return type + " " + name + " = " + value->toC() + ";";
    }
};
