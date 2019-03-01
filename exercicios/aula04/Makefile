CC = gcc
CFLAGS = -W -Wall -pedantic
EXEC = aula04
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

aula04: $(OBJ)
	@# gcc -o aula03 aula03.o main.o
	@$(CC) -o $@ $^

%.o: %.c
	@# gcc -o main.o -c aula03.c -W -Wall -pedantic
	@$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c aula04.h
	@$(CC) -o $@ -c $< $(FLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o
mrproper: clean
	@rm -rf $(EXEC)

run: $(EXEC)
	./$(EXEC)
