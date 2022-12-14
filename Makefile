CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g
RM=rm -rf
BETTY=betty
VALGRIND=valgrind
VFLAGS= --leak-check=full --show-leak-kinds=all ./monty 

TARGET=monty
SRC0=	func.c \
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
	pall.c

TARGET=monty
SRC4=	add.c \
	push.c \
	pall.c

TARGET=monty
SRC5=	nop.c

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

val2:
	$(VALGRIND) $(VFLAGS) bytecodes/2.m

val5:
	$(VALGRIND) $(VFLAGS) bytecodes/5.m

val6:
	$(VALGRIND) $(VFLAGS) bytecodes/6.m

val7:
	$(VALGRIND) $(VFLAGS) bytecodes/7.m

val4:
	$(VALGRIND) $(VFLAGS) bytecodes/4.m

val8:
	$(VALGRIND) $(VFLAGS) bytecodes/8.m

val0:
	$(VALGRIND) $(VFLAGS) bytecodes/0.m

valbig:
	$(VALGRIND) $(VFLAGS) bytecodes/big.m

val1:
	$(VALGRIND) $(VFLAGS) bytecodes/1.m

val:
	$(VALGRIND) $(VFLAGS) 1.m
