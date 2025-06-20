#include "parser.hpp"
#include <sstream>
#include <regex>

std::vector<DeclStmt> Parser::parse(const std::string& code) {
    std::vector<DeclStmt> result;
    std::istringstream stream(code);
    std::string line;

    std::regex pattern(R"((\w+)\s*:\s*(int)\s*=\s*(.+);)");

    while (std::getline(stream, line)) {
        std::smatch match;
        if (std::regex_match(line, match, pattern)) {
            std::string name = match[1];
            std::string type = match[2];
            std::string expr = match[3];

            // simplificação: suporta apenas expressões do tipo a + b * 2
            std::istringstream e(expr);
            std::string left, op, right;
            e >> left >> op >> right;

            std::shared_ptr<Expr> lhs, rhs;

            if (std::isdigit(left[0]))
                lhs = std::make_shared<ConstExpr>(std::stoi(left));
            else
                lhs = std::make_shared<VarExpr>(left);

            if (std::isdigit(right[0]))
                rhs = std::make_shared<ConstExpr>(std::stoi(right));
            else
                rhs = std::make_shared<VarExpr>(right);


            std::shared_ptr<Expr> exprNode = op.empty() ? lhs : std::make_shared<BinOpExpr>(op, lhs, rhs);

            result.push_back({name, type, exprNode});
        }
    }

    return result;
}
