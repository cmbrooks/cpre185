#include <stdio.h>
#include <stdbool.h>

bool isPrime (int n) {

    int factor = 3;

    if (n == 2) {
        return true;
    }

    if ((n % 2) == 0 || n < 2) {
        return false;
    }

    while ((factor * factor) <= n) {
        if ((n % factor) == 0) {
            return false;
        }
        factor += 2;
    }

    return true;

}

int main () {

    int i;
    for (i = 1; i < 100000000; i++) {
        if (isPrime(i)) {
            printf("%d is prime\n", i);
        }
    }

    return 0;

}
