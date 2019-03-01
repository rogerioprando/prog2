# cada file.c um arquivo objeto é criado com file.o
# o mesmo que OBJ = main.o aula03.o, mas assim inclui todos .o, a partir dos .c
CC = gcc
CFLAGS = -W -Wall -pedantic
EXEC = aula03
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# all: nome das regras a serem executadas, nesse caso: aula03
all: $(EXEC)

aula03: $(OBJ)
	$(CC) -o $@ $^
	@# $(CC) -o $@ $^ é o mesmo que:
	@# gcc -o aula03 aula03.o main.o

	@# %.c.%.o significa fazer um file.o a partir de file.c
	@# nesse caso, com todos arquivos .c
	@# %.c.%.o significa fazer um file.o a partir de file.c
	@# nesse caso, com todos arquivos .c
%o: %c
	@#$(CC) -o $@ $< $(CFLAGS)
	$(CC) -o $@ -c $< $(CFLAGS)
	@# $(CC): gcc.
	@# $@: Nome da regra. O mesmo que: %.o %.c (todos arquivos)
	@# $<: Nome da primeira dependência
	@# $(CC) -o $@ $< $(CFLAGS) é o mesmo que:
	@# gcc -o aula03.o -c ala03.c -W -Wall -pedantic

main.o: main.c aula03.h
	$(CC) -o $@ -c $< $(FLAGS)
	@# gcc -o main.o -c $(SRC) -W -Wall -pedantic

# PHONY: evita conflitos com possíveis arquivos com nome de açoes. (clean.c)
.PHONY: clean mrproper
# clean: Apaga todos arquivos intermediários. (arquivos objetos)
# mrproper: Apaga tudo que deve ser modificado. (executável)
clean:
	@rm -rf *.o
mrproper: clean
	@rm -rf $(EXEC)

run: $(EXEC)
	./$(EXEC)
