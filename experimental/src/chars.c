#include <stdio.h>

int main () {

	char a;
	scanf("%c", &a);

	printf("The character is: %c\n", a);
	printf("It's ASCII code is: %d\n", a);
	printf("The next character is: %c\n", a + 1);

	return 0;

}
