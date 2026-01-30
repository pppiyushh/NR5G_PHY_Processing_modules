CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99

SRC = src/scrambling.c src/modulation.c src/resource_mapper.c
OBJ = $(SRC:.c=.o)

test: all
	$(CC) $(CFLAGS) tests/test_ul_chain.c libphy.a -o test_ul

all: libphy.a

libphy.a: $(OBJ)
	ar rcs $@ $^

clean:
	rm -f src/*.o libphy.a