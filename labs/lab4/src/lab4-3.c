/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
double mag (double x, double y, double z);
int minutes (int millis);
int seconds (int millis);
int millis (int millis);

int main(void) {
	int t;
	double  ax, ay, az; 	


	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0
		printf("Echoing output: %5.3d, %3.4lf, %3.4lf, %3.4lf\n", t, ax, ay, az);	*/

/* 	CODE SECTION 1
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az));	*/
/* 	CODE SECTION 2 */
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az));
		
		fflush(stdout);
	}

return 0;
}

/* Put your functions here */
double mag (double x, double y, double z) {
	double magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return magnitude;
}

int minutes (int time) {
	int minsLeft = time / 60 / 1000; // Converts ms to minutes
	return minsLeft;
}

int seconds (int time) {
	int secsLeft = time / 1000;
	int minsUsed = minutes(time) * 60; // Converts minutes already used to seconds
	secsLeft -= minsUsed; // Discounts time already reported
	return secsLeft;
}

int millis (int time) {
	int msLeft = time;
	int minsUsed = minutes(msLeft) * 60 * 1000; // Converts minutes already reported to milliseconds
	msLeft -= minsUsed; // Discounts time already reported
	int secsUsed = seconds(msLeft) * 1000; // Converts seconds already reported to milliseconds
	msLeft -= secsUsed; // Discounts time already reported
	return msLeft;
}