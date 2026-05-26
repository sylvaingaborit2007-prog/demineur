CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude -g

SRC = source/main.c source/utils.c source/menu.c source/fonctions_main.c
OBJ = $(SRC:source/%.c=obj/%.o)

TARGET = demineur

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

obj/%.o: source/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o $(TARGET)

.PHONY: all clean
