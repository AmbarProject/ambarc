# Nome do executável
EXEC = ambar

# Fontes
FLEX_SRC = flex/ambar.l
BISON_SRC = bison/parser.y
AST_SRC = AST.hpp NumberExpr.hpp BinaryExpr.hpp
SRC = main.cpp

# Arquivos gerados
BISON_CPP = parser.tab.c
BISON_HPP = parser.tab.h
FLEX_CPP = lexer.cpp

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. 
LDFLAGS = -lfl

# Regra padrão
all: $(EXEC)

# Compilação do executável
$(EXEC): $(SRC) $(FLEX_CPP) $(BISON_CPP) $(AST_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC) $(FLEX_CPP) $(BISON_CPP) $(LDFLAGS)

# Geração dos arquivos do Bison
$(BISON_CPP) $(BISON_HPP): $(BISON_SRC)
	bison -d -o $(BISON_CPP) $(BISON_SRC)

# Geração do Flex
$(FLEX_CPP): $(FLEX_SRC)
	flex -o $(FLEX_CPP) $(FLEX_SRC)

# Limpeza de arquivos gerados
clean:
	rm -f $(EXEC) $(FLEX_CPP) $(BISON_CPP) $(BISON_HPP)

.PHONY: all clean
