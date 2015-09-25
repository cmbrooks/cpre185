/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */

int main(void) {
	int a, b, x, y, joystick, buttonsPressed;

	while (TRUE) {
		scanf("%d, %d, %d, %d, %d,", &a, &y, &x, &b, &joystick);
		buttonsPressed = (a + b + x + y + joystick);
		printf("%d buttons are being pressed\n", buttonsPressed);
		fflush(stdout);
	}

	return 0;
}

/* Put your functions here */