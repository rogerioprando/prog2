#include <stdio.h>

#define FIRST_PART      7 
#define LAST_PART       5 
#define ALL_PARTS       FIRST_PART + LAST_PART 

int main() { 
    printf("O quadrado de todas as partes vale %d\n", 
	ALL_PARTS * ALL_PARTS);

	// 7 + 5 * 7 + 5 = 47
    return (0);
} 
