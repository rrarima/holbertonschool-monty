CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
RM=rm -rf

TARGET=monty
SRC0=	push.c \
	pall.c

SRC1=	pint.c \
	push.c

SRC2=	pop.c \
	push.c \
	pall.c

SRC3=	swap.c \
	push.c \
	pall.c \

SRC4=	add.c \
	push.c \
	pall.c

SRC5=	nop.c

all: 0 1 2 3 4 5

clean:
	$(RM) *~ \#*\# \.\#* \
        $(TARGET)

re: clean all

0:	$(CC) $(CFLAGS) $(SRC0) -o $(TARGET)

1:	$(CC) $(CFLAGS) $(SRC1) -o $(TARGET)

2:	$(CC) $(CFLAGS) $(SRC2) -o $(TARGET)

3:	$(CC) $(CFLAGS) $(SRC3) -o $(TARGET)

4:	$(CC) $(CFLAGS) $(SRC4) -o $(TARGET)

5:	$(CC) $(CFLAGS) $(SRC5) -o $(TARGET)

betty:
	betty $(SRC0) $(SRC1) $(SRC2) $(SRC3) $(SRC4) $(SRC5)
