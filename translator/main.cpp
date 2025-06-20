#include <iostream>
#include "ast.hpp"

int main() {
    std::vector<std::shared_ptr<Stmt>> program;

    // Simula parsing
    auto a = std::make_shared<DeclStmt>("a", "int", std::make_shared<ConstExpr>(10));
    auto b = std::make_shared<DeclStmt>("b", "int", std::make_shared<ConstExpr>(20));
    auto c = std::make_shared<DeclStmt>("c", "int",
        std::make_shared<BinOpExpr>("+",
            std::make_shared<VarExpr>("a"),
            std::make_shared<VarExpr>("b")
        )
    );

    program.push_back(a);
    program.push_back(b);
    program.push_back(c);

    for (const auto& stmt : program) {
        std::cout << stmt->toC() << std::endl;
    }

    return 0;
}
