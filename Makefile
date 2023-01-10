CFLAGS = -g -Wall -Wextra -Iinclude
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
CC=gcc

all : bin/prog1
all : bin/prog2
all : bin/prog3
all : bin/prog4

bin/prog1 : $(OBJ) prog/main_a1.o
	$(CC) $^ $(LDFLAGS) -o $@

bin/prog2 : $(OBJ) prog/main_a2.o
	$(CC) $^ $(LDFLAGS) -o $@

bin/prog3 : $(OBJ) prog/main_l1.o
	$(CC) $^ $(LDFLAGS) -o $@

bin/prog4 : $(OBJ) prog/main_l2.o
	$(CC) $^ $(LDFLAGS) -o $@


clean :
	$(RM) -f $(OBJ) bin/*