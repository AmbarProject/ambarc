#include <iostream>
#include <cstdio>

extern "C++" {
    int yyparse(void);
    extern FILE* yyin;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            std::cerr << "Erro ao abrir o arquivo: " << argv[1] << std::endl;
            return 1;
        }
    }

    int result = yyparse();
    
    if (result == 0) {
        std::cout << "Código válido segundo a gramática Ambar." << std::endl;
    } else {
        std::cerr << "Erro na análise sintática." << std::endl;
    }

    if (yyin && yyin != stdin) {
        fclose(yyin);
    }

    return result;
}