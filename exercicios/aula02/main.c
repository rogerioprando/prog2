#include <stdio.h>

#define QUADR(x) ((x) * (x))

#define set_bit(y, bit) (y |= (0x01 << bit))
#define clr_bit(y, bit) (y &= ~(0x01 << bit))
#define cpl_bit(y, bit) (y ^= (0x01 << bit))
#define tst_bit(y, bit) (y & (0x01 << bit))



int main()
{
	int a = 0x0F;

	printf("a set : %x \n", set_bit(a,1));
	printf("a clr : %x \n", clr_bit(a,1));
	printf("a cpl : %x \n", cpl_bit(a,1));
	printf("a tst : %x \n", tst_bit(a,0));
	printf("a tst : %x \n", tst_bit(a,4));
	printf("a tst : %x \n", tst_bit(a,7));


	return 0;
}