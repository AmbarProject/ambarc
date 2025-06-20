#pragma once
#include "ast.hpp"
#include <vector>
#include <string>

class Parser {
public:
    std::vector<DeclStmt> parse(const std::string& code);
};
