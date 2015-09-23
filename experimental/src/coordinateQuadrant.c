#include <stdio.h>

int getQuadrant (double x, double y) {

	int quadrant;

	if (x > 0) {
		if (y > 0) {
			quadrant = 1;
		} else if (y < 0) {
			quadrant = 4;
		} else {
			quadrant = -1;
		}
	} else if (x < 0) {
		if (y > 0) {
			quadrant = 2;
		} else if (y < 0) {
			quadrant = 3;
		} else {
			quadrant = -1;
		}
	} else {
		if (y != 0) {
			quadrant = -2;
		} else {
			quadrant = -3;
		}
	}

	return quadrant;

}

int main () {

	double x, y;
	int quadrant;
	char againResponse;
	int exitApp = 0;

	while (exitApp == 0) {

		printf("Enter X coordinate: ");
		scanf("%lf", &x);
		printf("Enter Y coordinate: ");
		scanf("%lf", &y);

		quadrant = getQuadrant(x, y);

		if (quadrant == -1) {
			printf("The point (%lf, %lf) lies on the x-axis\n", x, y);
		} else if (quadrant == -2) {
			printf("The point (%lf, %lf) lies on the y-axis\n", x, y);
		} else if (quadrant == -3) {
			printf("The point (%lf, %lf) is at the origin\n", x, y);
		} else {
			printf("Coordinate (%lf, %lf) is in quadrant %d\n", x, y, quadrant);
		}

		printf("Enter another coordinate? (y/n): ");
		scanf(" %c", &againResponse);

		if (againResponse == 'n') {
			printf("Goodbye\n");
			exitApp = 1;
		} else if (againResponse != 'y') {
			printf("Response not reognised. Exiting application.\n");
			exitApp = 1;
		}

	}
	return 0;

}
