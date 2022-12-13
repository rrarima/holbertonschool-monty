CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
RM=rm -rf
BETTY=betty
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./monty

TARGET=monty
SRC0=	func.c \
	main.c

all: 0

0:
	$(CC) $(CFLAGS) $(SRC0) -o $(TARGET)


clean:
	$(RM) *~ \#*\# \.\#* \
        $(TARGET)

re: clean all

betty:
	$(BETTY) $(SRC0)

val:
	$(VALGRIND) $(VFLAGS) 1.m
