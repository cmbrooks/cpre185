#include <stdio.h>

#define PERBOX3 36
#define PERBOX4 25
#define PERRACK3 10
#define PERRACK4 8

int numRacks (int shellsPerRack, int shellsPerBox, int numBoxes) {

	int numShells = numBoxes * shellsPerBox;
	int numRacks = numShells / shellsPerRack;

	if ((numShells % shellsPerRack) > 0) {
		numRacks += 1;
	}

	return numRacks;

}

int main () {

	int numBoxes3, numBoxes4;
	printf("Enter the number of boxes seperated by commas (3\" and 4\" shell boxes accordingly): ");
	scanf("%d,%d", &numBoxes3, &numBoxes4);

	int numRacks3 = numRacks(PERRACK3, PERBOX3, numBoxes3);
	int numRacks4 = numRacks(PERRACK4, PERBOX4, numBoxes4);

	printf("You will need %d 3\" racks and %d 4\" racks.\n", numRacks3, numRacks4);

	return 0;

}
