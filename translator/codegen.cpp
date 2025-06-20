#include "codegen.hpp"

std::string CodeGenerator::generate(const std::vector<DeclStmt>& stmts) {
    std::string code = "#include <stdio.h>\n\nint main() {\n";
    for (const auto& stmt : stmts) {
        code += "    " + stmt.toC() + "\n";
    }
    code += "    printf(\"Resultado: %d\\n\", c);\n";
    code += "    return 0;\n}\n";
    return code;
}
