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
    	indexOfMin = i;
    	
    	//Finds the index of the smallest value past the sorted portion of the list
    	for (j = 0; j < listSize; j++) {
    		if (list[j] < list[indexOfMin]) {
    			indexOfMin = j;
    		}
    	}
    	
    	//Swap the current number with the newly found minimum
    	if (indexOfMin != j) {
    		temp = list[i];
    		list[i] = list[indexOfMin];
    		list[indexOfMin] = temp;    		
    	}
    	
    }
    
    //Print sorted array
    printf("\n~=~=~=~=~\n\n(Hopefully) Sorted list:\n");
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
