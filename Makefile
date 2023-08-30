SRC_DIR   := src
OBJ_DIR   := obj
BIN_DIR   := bin

# The generated executable file
EXE       := $(BIN_DIR)/wc

# C flags, options, etc.
LDFLAGS   :=
LDLIBS    :=
INCLUDE   :=
CC        := clang
STD       := -std=c17
OPT       := -O3
CFLAGS  := $(STD) -g -Wall -Wextra -Werror $(OPT) $(INCLUDE)

# All the C files
SRC       := $(wildcard $(SRC_DIR)/*.c)
# All the object files
OBJ       := $(subst .cc, .o, $(SRC))

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(STD) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
