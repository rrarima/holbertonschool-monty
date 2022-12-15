CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
RM=rm -rf
BETTY=betty
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./monty

TARGET=monty

SRC0=	opcodes1.c \
	opcodes2.c \
	main.c \
	find_opcode.c \
	free_stack.c \
	opcodes3.c

all: 0 1 2 3 4 5

0:
	$(CC) $(CFLAGS) $(SRC0) -o $(TARGET)

clean:
	$(RM) *~ \#*\# \.\#* \
        $(TARGET)

re: clean all

betty:
	$(BETTY) $(SRC0)

val00:
	$(VALGRIND) $(VFLAGS) bytecodes/00.m

valdebug:
	$(VALGRIND) $(VFLAGS) debug.m
