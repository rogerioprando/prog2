#include "aula04.h"

/* Alocação dinâmica

malloc: aloca quantidade de memória
malloc(size_t size): retorna o ponteiro para região alocada, se falhar retorna NULL.

calloc: aloca quantidade específica de memória, zerando seu conteúdo

realloc: redimensiona um tamanho já alocado

free: libera espaço alocado

Modificar o exercı́cio da leitura dos dados do arquivo
“winterGames.csv” para alocação dinâmica. Usar o seguinte
algoritmo:
1 Contar o número de linhas para estimar o número de elementos.
2 Alocar memória suficiente para armazenar todos os dados.
3 Utilizar a seguinte estrutura, alocando também a memória para o nome:
struct jogosInver {
  unsigned char pos;
  char ∗nome; // < − nome com alocação
(...)
};

4 Exibir os dados lidos na tela.
5 Desalocar toda a memória.
*/
void runAula04(void){

  printf("Aul04 has started !\n");

  // char k = 3;
  // char *ptr_k = &k;
  //
  // printf("addr: %p value: %d\n", ptr_k, *ptr_k);
  //
  // int *num, length, i;
  //
  // scanf("%d", &length);
  //
  // num = (int*) malloc(sizeof(int) *length);
  //
  // if(num == NULL){
  //   perror("main:");
  //   exit(1);
  // }
  //
  // for(i = 0; i<length; i++){
  //     scanf("%d", &num[i]);
  // }
  //
  // for(i =0; i<length; i++){
  //   printf("\nNums: %d", num[i]);
  // }

  //open file
  FILE *fp = fopen("files/dados.csv", "r");

  if(fp == NULL){
    perror("Error main fopen()");
    exit(EXIT_FAILURE);
  }

  int c, count = 0;

  char linha[100];

  //count lines
  while((c = fgetc(fp)) != EOF){
    if(c == '\n') count++;
  }
  printf("\n\n\nTOTAL COUNT:%d linhas \n", count);

  // begin of file
  fseek(fp, 0, SEEK_SET);

  // aloca memória para a struct
  winterGame *wg;
  winterGame *wg_sto;
  // wg esta apontando para o início da alocação
  wg = (winterGame*) malloc(count * sizeof(winterGame));

  wg_sto = wg;
  printf("ADDR STRUCT wg: %p and wg_sto %p\n", (void *) wg, (void *) wg_sto);

  //printf("ADDRESS OF WG AT START\n\n: %p", &wg);


  while(fgets(linha, sizeof(linha), fp) !=  NULL){
    // aloca memória para cada nome
    wg->nome = (char *) malloc(30 * sizeof(char));
    sscanf(linha, "%d,%50[^,],%d,%d,%d, %d\n",
          (int *)&wg->pos, wg->nome, &wg->gold, &wg->silver, &wg->bronze, &wg->total);

    printf("[%.2d]\t ||%.2d|| %.2d|%.2d|%.2d  \t%s",
          wg->pos, wg->total, wg->gold, wg->silver, wg->bronze,wg->nome);

    wg++;
    printf("ADDR wg: %p\n", (void *) wg);

  }

  fclose(fp);

  wg = wg_sto;  // reset pointer

  FILE *fp_format = fopen("files/games_format.txt", "w");

  if (fp_format == NULL){
    perror("Error open");
    exit(EXIT_FAILURE);
  }

  fprintf(fp_format, "RESULTADO DOS JOGOS");

  for(int i = 0; i < count; i++){
    fprintf(fp_format, "\n[%.2d]\t ||%.2d|| %.2d|%.2d|%.2d  \t%s",
            wg->pos, wg->total, wg->gold, wg->silver, wg->bronze,wg->nome);
    wg++;
  }

  fclose(fp_format);

  wg = wg_sto;   // reset ponteiro

  char country[] = "Cana da (CAN)";

  char *a;
  a = find_country(wg, country, count);

  printf("\n%s\n", a);

  winterGame *b;
  b = find_country_data(wg, country, count);

  printf("\n%s com %d medalhas e na %dª colocação.\n ", b->nome, b->total, b->pos);

}

char * find_country(winterGame *g, char country[], int counts){
  int i = 0;
  for(i = 0; i < counts; i++)
  {
    if(!strcmp(g->nome, country))
    {
      printf("Same strings \n");
      return g->nome;
    }
    g++;
  }

  return "Country not found!\n";

}

winterGame *find_country_data(winterGame *g, char country[], int counts){
  int i;
  for(i = 0; i <counts; i++){
    if(!strcmp(g->nome, country)){
      return g;
    }
    g++;
  }
  return g;
}
