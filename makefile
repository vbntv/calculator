CFLAG = -Wall -Werror -o
BIN_DIR = bin
BUILD_DIR = build/src
SRC_DIR = src
CC = gcc
DIRGUARD=@mkdir -p $(@D)

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = $(BIN_DIR)/main

$(TARGET): $(OBJ)
	@$(DIRGUARD)
	@$(CC) $(CFLAG) $@ $(OBJ) -lm

$(OBJ): $(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@$(DIRGUARD)
	@$(CC) -c $(CFLAG) $@ $<

.PHONY: clean

clean:
	@rm -f $(BUILD_DIR)/*.o $(TARGET)

