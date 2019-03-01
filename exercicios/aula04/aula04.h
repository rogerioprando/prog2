#ifndef _H_AULA04
#define _H_AULA04

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct winterGames{
  unsigned char pos;
  char *nome;
  int gold;
  int silver;
  int bronze;
  int total;
} winterGame;

void runAula04(void);
char *find_country(winterGame *g, char country[], int counts);
winterGame *find_country_data(winterGame *g, char country[], int counts);

#endif
