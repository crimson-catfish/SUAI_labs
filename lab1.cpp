#include <stdio.h>

int main()
{
	unsigned char a, b, c, d;

	a = 117 & -80;
	printf("117 AND -80 = (48) = %i\n", a);
	b = -117 ^ 21;
	printf("-117 XOR 21 = (158) = %i\n", b);
	c = 117 >> 3;
	printf("117 >> 3 = (14) = %i\n", c);
	d = -117 ^ ~15 & (~82 | -25);
	printf("-117 XOR NOT 15 AND (NOT 82 OR -25) = (107) = %i\n", d);

	return 0;
}