/*Given hours, minutes and seconds, output the percent of a day*/

#include <stdio.h>

int main() {

	int hours, mins;
	double secs;
	double percentDay;
	
	printf("Hours: ");
	scanf("%d", &hours);
	printf("Minutes: ");
	scanf("%d", &mins);
	printf("Seconds: ");
	scanf("%lf", &secs);

	percentDay = 100 * (hours/24.0 + mins/(24.0*60) + secs/(24.0*60*60));
	
	printf("Entered values: %d hours, %d minutes and %lf seconds\n", hours, mins, secs);
	printf("Percent of the day: %6.2lf\n", percentDay);
	
	return 0;

}
