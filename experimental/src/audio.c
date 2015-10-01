#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define TOLERANCE 0.05

bool closeToZero (double x) {
    if (labs(x) < TOLERANCE) {
        return true;
    } else {
        return false;
    }
}

int main() {

    double time, value, quietTime;
    int numMatched;

    do {
        numMatched = scanf(" %lf, %lf", &time, &value);
    } while(numMatched == 2 && !closeToZero(value));

    if (numMatched < 2) {
        return 0;
    }

    quietTime = time;
    printf("Quiet Time: %lf\n", quietTime);

    return 0;

}
