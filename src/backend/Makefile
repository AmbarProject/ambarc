CC = g++
CFLAGS = -std=c++17 -Wall
FLEX = flex
BISON = bison

BUILD_DIR = build
BISON_DIR = bison
FLEX_DIR = flex
SRC_DIR = .

BISON_SRC = parser.y
FLEX_SRC = ambar.l
MAIN_SRC = main.cpp

BISON_OUT = $(BUILD_DIR)/parser.tab.c
BISON_HEADER = $(BUILD_DIR)/parser.tab.h
FLEX_OUT = $(BUILD_DIR)/lex.yy.c
TARGET = ambar_compiler

all: dirs $(TARGET)

dirs:
	mkdir -p $(BUILD_DIR)

$(BISON_OUT) $(BISON_HEADER): $(BISON_DIR)/$(BISON_SRC)
	$(BISON) -d -o $(BISON_OUT) $(BISON_DIR)/$(BISON_SRC)

$(FLEX_OUT): $(FLEX_DIR)/$(FLEX_SRC) $(BISON_HEADER)
	$(FLEX) -o $(FLEX_OUT) $(FLEX_DIR)/$(FLEX_SRC)

$(TARGET): $(BISON_OUT) $(FLEX_OUT) $(SRC_DIR)/$(MAIN_SRC)
	$(CC) $(CFLAGS) -I$(BUILD_DIR) -o $@ $(BISON_OUT) $(FLEX_OUT) $(SRC_DIR)/$(MAIN_SRC) -lfl

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean dirs