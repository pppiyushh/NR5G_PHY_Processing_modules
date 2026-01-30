CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99

SRC = src/scrambling.c src/modulation.c
OBJ = $(SRC:.c=.o)

all: libphy.a

libphy.a: $(OBJ)
	ar rcs $@ $^

clean:
	rm -f src/*.o libphy.a