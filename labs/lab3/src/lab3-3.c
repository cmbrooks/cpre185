// CprE 185: Lab 3
// Problem 3: Esplora

#include <stdio.h>
#include <math.h>


int main() {
	double x, y, z;

	while (1) {
		/*
		Gets the X, Y and Z values printed to the terminal by explore.exe
		*/
		scanf("%lf , %lf , %lf", &x, &y, &z);

		/*
		Takes the X, Y and Z values and computes the
		magnitude of the vector <X, Y, Z>
		*/
		printf("Magnitude of (%5.2lf,%5.2lf,%5.2lf) is: %6.2lf\n",
			x, y, z, sqrt(x*x+y*y+z*z) );
	}

	return 0;
}
