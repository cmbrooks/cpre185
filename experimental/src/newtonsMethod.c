#include <stdio.h>
#include <math.h>

/* Returns a value for the mathmatical function f(x), given x */
double f(double x) {
    return 2*x*x;
}

/* Returns a value for the derivative of the function f(x), given x */
double fPrime (double x) {
    return 4*x;
}

int main() {

    double x0, x1;
    char approxType;
    int i;

    printf("Enter a guess of the root:\n");
    scanf("%lf", &x0);
    printf("Set number of approximations (a) or within a tollerance (t)?\n");
    scanf(" %c", &approxType);

    if (approxType == 'a') {

        printf("Enter the number of approximations:\n");
        scanf("%d", &i);

        for (i; i > 0; i--) {
            x1 = x0 - (f(x0) / fPrime(x0));
            x0 = x1;
        }

        printf("Approximation: %10lf\n", x1);

    } else if (approxType == 't') {

        double tollerance, answer, diff;
        int tries = 0;
        printf("Expected answer:\n");
        scanf("%lf", &answer);
        diff = x0;
        printf("Enter a tollerance:\n");
        scanf("%lf", &tollerance);

        while (diff >= tollerance) {
            x1 = x0 - (f(x0) / fPrime(x0));
            x0 = x1;
            diff = fabs(answer - x1);
            tries++;
        }

        printf("It took %d tries to approimate the answer (approximation: %10lf)\n", tries, x1);

    } else {
        printf("Not a valid approximation type\n");
    }

    return 0;

}
