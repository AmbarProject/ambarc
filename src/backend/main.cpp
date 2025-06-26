#include <iostream>

extern int ambar_parse();
extern FILE* ambar_in;

int main(int argc, char **argv) {
    if (argc > 1) {
        ambar_in = fopen(argv[1], "r");
        if (!ambar_in) {
            std::cerr << "Erro ao abrir o arquivo: " << argv[1] << std::endl;
            return 1;
        }
    }

    if (ambar_parse() == 0) {
        std::cout << "Código válido segundo a gramática Ambar.\n";
    } else {
        std::cerr << "Erro na análise sintática.\n";
    }

    return ambar_parse();
}