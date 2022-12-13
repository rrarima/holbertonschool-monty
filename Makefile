CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
RM=rm -rf
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./monty bytecodes/00.m

TARGET=monty
SRC0=	push.c \
	pall.c

TARGET=monty
SRC00=	func.c \
	main.c

TARGET=monty
SRC1=	pint.c \
	push.c

TARGET=monty
SRC2=	pop.c \
	push.c \
	pall.c

TARGET=monty
SRC3=	swap.c \
	push.c \
	pall.c \

TARGET=monty
SRC4=	add.c \
	push.c \
	pall.c

TARGET=monty
SRC5=	nop.c

all: 0 1 2 3 4 5

0:
	$(CC) $(CFLAGS) $(SRC0) -o $(TARGET)

00:
	$(CC) $(CFLAGS) $(SRC00) -o $(TARGET)

1:
	$(CC) $(CFLAGS) $(SRC1) -o $(TARGET)

2:
	$(CC) $(CFLAGS) $(SRC2) -o $(TARGET)

3:
	$(CC) $(CFLAGS) $(SRC3) -o $(TARGET)

4:
	$(CC) $(CFLAGS) $(SRC4) -o $(TARGET)

5:
	$(CC) $(CFLAGS) $(SRC5) -o $(TARGET)


clean:
	$(RM) *~ \#*\# \.\#* \
        $(TARGET)

re: clean all

betty:
	betty $(SRC0) $(SRC1) $(SRC2) $(SRC3) $(SRC4) $(SRC5)

val:
	$(VALGRIND) $(VFLAGS)
