#include <stdio.h>

int main (int argc, char* argv[]) {
	
	int x, y, z;
	
	printf("Enter a width: ");
	scanf("%d", &x);
	printf("Enter a height: ");
	scanf("%d", &y);
	printf("Enter a length: ");
	scanf("%d", &z);
	printf("A %d by %d by %d rectangular prism's volume is %d\n", x, y, z, x * y * z);
	
	return 0;

}