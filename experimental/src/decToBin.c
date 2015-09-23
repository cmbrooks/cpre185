/* Given a number from 0-15, output that number in binary. */

#include <stdio.h>

int main () {

	int x;
	int remainder;
	int b0;
	int b1;
	int b2;
	int b3;
	
	printf("Input a number between 0 and 15: ");
	scanf("%d", &x);

	b3 = x / 8;
	remainder = x % 8;
	b2 = remainder / 4;
	remainder %= 4;
	b1 = remainder / 2;
	remainder %= 2;
	b0 = remainder / 1;

	printf("%d is %d%d%d%d in binary\n", x, b3, b2, b1, b0);
	
	return 0;

}
