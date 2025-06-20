#include <fstream>
#include <iostream>
#include "parser.hpp"
#include "codegen.hpp"

int main() {
    std::ifstream in("exemplo.am");
    if (!in) {
        std::cerr << "Erro ao abrir exemplo.am\n";
        return 1;
    }

    std::string code((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

    Parser parser;
    auto stmts = parser.parse(code);

    std::string c_code = CodeGenerator::generate(stmts);

    std::ofstream out("gerado.c");
    out << c_code;
    out.close();

    std::system("gcc gerado.c -o gerado");
    std::cout << "\n== Saída ==\n";
    std::system("./gerado");

    return 0;
}
