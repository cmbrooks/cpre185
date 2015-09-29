#include <stdio.h>
#include <stdbool.h>

int getGuess () {
    int guess;
    printf("Guess a number between 1 and 10: ");
    scanf("%d", &guess);
    return guess;
}

int main() {

    int secretNumber;
    int guess;
    bool guessed;

    secretNumber = 8;
    guessed = false;

    while (!guessed) {
        guess = getGuess();
        if (guess > 10) {
            printf("What kind of guess was that? I said between 1 and 10!\n");
        } else if (guess < secretNumber) {
            printf("Higher\n");
        } else if (guess > secretNumber) {
            printf("Lower\n");
        } else {
            guessed = true;
        }
    }

    printf("Congradulations! You guessed the secret number\n");

    return 0;

}
