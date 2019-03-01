#include "aula03.h"

/*

LIST OF FUNCTIONS (manipulating files)

Open File:        FILE* fopen(char* filename, char* mode)
Close File:       int fclose (FILE * stream)
Read character:   int fgetc(FILE * stream)
Unread character: int ungetc(int character, FILE * stream)
Read string:      char * fgets(char * str, int num, FILE * stream)
Check end file:   int feof(FILE * stream)
Read format data: int fscanf(FILE * stream, const char * format, ...)

Write character:  int fputc(int character, FILE * stream)
Write string:     int fputs(const char * str, FILE * stream)
Write format data:int fprintf(FILE * stream, const char * format, ...)
Check error:      int ferror(FILE * stream)
Print error desc: perror(const char * str)
Move in file:     void rewind(FILE * stream)
Move to local:    int fseek(FILE * stream, long int offset, int origin)

Open binary file:   FILE* fopen(char* filename, char* mode)
Write binary file:  size_t fwrite (const void * ptr, size_t size, size_t count, FILE * stream)
Read binary file:   size_t fread(void * ptr, size_t size, size_t count, FILE * stream)

*/

void runAula03(void){

  printf("Aula03 has started!!\n");

  // NULL: there is a value but the value there is no meaning. NULL for strings
  // EOF: represents the file was completed no values are remaining. EOF for files. ASCII value -1
  // \0: end of string. ASCII value 0
  // fopen requires stdio.h
  // fopen returns a pointer for the new file. if cannot opened, return null pointer.

  // Open file
  FILE *fp = fopen("files/dados.csv", "r");
  int cmd;

  if(fp == NULL){
    perror("Erro em main: fopen\n");
    exit(EXIT_FAILURE);
  }

  printf("1 . Ler arquivo\n");
  printf("2 . Ler arquivo e formatar em number language\n");
  printf("3 . Ler arquivo como strings\n");
  printf("4 . Ler arquivo formatado\n");
  printf("5 . Ler arquivo winterGames.csv\n");
  printf("0 . SAIR\n");


  printf("Entre com uma opção listada acima:  ");
  scanf("%d", &cmd);

  switch (cmd) {
    case 1: reading_file(fp); break;
    case 2: number_language(fp); break;
    case 3: reading_strings(fp); break;
    case 4: reading_formating(fp); break;
    case 5: winter_games(); break;
    case 0:
    default:
      printf("\nSaindo... \n");
      exit(0);
    break;
  }

  fclose(fp);

}

void runAula03_writing(){

}


// Read file up to EOF
void reading_file(FILE *fp){

  int c;
  while((c = fgetc(fp)) != EOF){
    printf("%c", c);
  }
}

// Read file up to EOF, change a e o i to numbers 4 3 0 1.
void number_language(FILE *fp){

  int c;
  while((c = fgetc(fp)) != EOF){
    switch (c) {
      case 'a': ungetc('4', fp); break;
      case 'e': ungetc('3', fp); break;
      case 'i': ungetc('1', fp); break;
      case 'o': ungetc('0', fp); break;
      default: printf("%c", c); break;
    }
  }

}

// Read string in file up to NULL
void reading_strings(FILE *fp){

    char c[BUFFER];
    while(fgets(c, BUFFER, fp) != NULL){
      printf("linha: %s \n", c);
    }

}

void reading_formating(FILE *fp){
  // %d integer, %c character, %s string

  char nome[BUFFER];
  int idade;
  char sexo;

  while(!feof(fp)){
    fscanf(fp, "%80[^;];%d;%c\n", nome, &idade, &sexo);

    printf("%s \t- %d \t- %c\n", nome, idade, sexo);

  }


}

// Melhor não usar scanf, fscanf, fgets
// Utilizar funções que limitam o buffer explicitamente, fgets e depois formatar com sscanf.

void winter_games()
{
  char c[BUFFER];

  struct WinterGames {
    int pos;
    char country[50];
    int gold;
    int silver;
    int bronze;
    int total;
  };

  struct WinterGames london2018;

  FILE *games = fopen("files/winterGames.csv", "r");

  if(games == NULL){
    perror("Erro em main: fopen\n");
    exit(EXIT_FAILURE);
  }

  // while(!feof(games)){
  //
  //   fscanf(games, "%2[^,],%50[^,],%d,%d,%d, %d\n", london2018.pos, london2018.country, &london2018.gold, &london2018.silver, &london2018.bronze, &london2018.total);
  //   printf("Pos: %s \t T: %d  \t G: %d S: %d B: %d \t %s\n", london2018.pos, london2018.total, london2018.gold, london2018.silver, london2018.bronze, london2018.country);
  //
  // }

  while(fgets(c, BUFFER, games) != NULL){
    //printf("%s\n", c);
    sscanf(c, "%d,%50[^,],%d,%d,%d, %d\n",  &london2018.pos, london2018.country, &london2018.gold, &london2018.silver, &london2018.bronze, &london2018.total);
    printf("|%d|\tMedals: %d (G %d, B %d, S %d)\t | Country: %s\n", london2018.pos, london2018.total, london2018.gold, london2018.silver, london2018.bronze, london2018.country);
  }

  fclose(games);
}
