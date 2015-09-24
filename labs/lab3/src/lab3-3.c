// CprE 185: Lab 3
// Problem 3: Esplora

/*
The expression computed in the printf() statement is useful in interpreting
the data coming from explore.exe because it is easier to visualize motion as
a single vector rather than trying to imagine how three seperate accelerations
would affect the motion of an object at the same time.
*/

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
