#include <stdio.h>
#include <stdbool.h>

int main () {

    int num;
    bool prime = true;
    int divisibleBy;

    printf("Enter an integer:\n");
    scanf(" %d", &num);

    for (int i = 2; i < num; i++) {
        if ((num % i) == false)  {
            divisibleBy = i;
            prime = false;
            break;
        }
    }

    if (prime == true) {
        printf("%d is a prime number\n", num);
    } else {
        printf("%d is not a prime number, it is divisible by %d\n", num, divisibleBy);
    }

    return 0;
}
