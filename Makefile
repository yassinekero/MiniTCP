CC=gcc
CFLAGS = -Wall -g -Iinclude -MMD -MP -O0

SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build


SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

TARGET = bin 

all: $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)


clean:
	rm -rf $(OBJ_DIR) $(TARGET)

rebuild: clean all
