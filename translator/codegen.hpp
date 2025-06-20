#pragma once
#include "ast.hpp"
#include <vector>
#include <string>

class CodeGenerator {
public:
    static std::string generate(const std::vector<DeclStmt>& stmts);
};
