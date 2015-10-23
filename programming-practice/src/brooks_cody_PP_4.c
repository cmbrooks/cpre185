/*
Cody Brooks
cmbrooks@iastate.edu
CPRE 185 Section  B
Programming Practice NUMBER
    <Reflection 1 What were you trying to learn or achieve?>
        To use arrays and loops in a practical application. To sort a random list
        of numbers by the method of selection sorting.
    <Reflection 2 Were you successful? Why or Why not?>
        Yes, I vas successful because I could initialize any size  list of
        randomly generated numbers and print a sorted list.
    <Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
        I may have changed the method of sorting. This algorithm has a best and
        worst case efficiercy of O(n^2). A merge sort would be much more efficient,
        but much more complicated to code.
    <Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
        The most important thing that I learned was the importance of understanding
        the problem and propperly planning before starting to write code.
*/

/* Selection Sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntArray (int array[], int size);

int main () {

    int listSize = 10;
    int list[listSize];
    int i;
    int j;
    int temp;
    int indexOfMin;
    srand((int)time(0));

    //Generate random numbers to fill the array
    for (i = 0; i < listSize; i++) {
        list[i] = rand() % 100;
    }

	//Print the generated array
    printf("Unsorted list:\n");
    printIntArray(list, listSize);
    printf("\n~=~=~=~=~\n");

    //Sort list
    for (i = 0; i < listSize - 1; i++) {

    	//Assumes that everything already passed by the outer loop is sorted
    	indexOfMin = listSize - 1;

    	//Finds the index of the smallest value past the sorted portion of the list
    	for (j = listSize - 1; j >= i; j--) {
    		if (list[j] < list[indexOfMin]) {
    			indexOfMin = j;
    		}
    	}

    	//Swap the current number with the newly found minimum
    	if (indexOfMin != j) {
    		temp = list[indexOfMin];
    		list[indexOfMin] = list[i];
    		list[i] = temp;
    	}

    }

    //Print sorted array
    printf("\nSorted list:\n");
    printIntArray(list, listSize);

    return 0;

}

void printIntArray (int array[], int size) {
	int i;
	printf("[");
	for (i = 0; i < size; i++) {
		if (!(i == size - 1)) {
			printf("%d, ", array[i]);
		} else {
			printf("%d", array[i]);
		}
	}
	printf("]\n");
}
