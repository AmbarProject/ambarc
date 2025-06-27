# Diretórios
BISON_DIR = ./bison
FLEX_DIR = ./flex

# Arquivos
BISON_FILE = $(BISON_DIR)/parser.y
FLEX_FILE = $(FLEX_DIR)/ambar.l

# Saídas geradas
BISON_OUTPUT_C = parser.tab.c
BISON_OUTPUT_H = parser.tab.h
FLEX_OUTPUT = lex.yy.c

# Compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Alvo final
TARGET = ambar
SOURCES = main.cpp $(BISON_OUTPUT_C) $(FLEX_OUTPUT)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(BISON_OUTPUT_C) $(BISON_OUTPUT_H): $(BISON_FILE)
	bison -d -o $(BISON_OUTPUT_C) $(BISON_FILE)

$(FLEX_OUTPUT): $(FLEX_FILE)
	flex -o $(FLEX_OUTPUT) $(FLEX_FILE)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) *.o parser.tab.* lex.yy.c
