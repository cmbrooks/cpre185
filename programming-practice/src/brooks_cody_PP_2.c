/*
Cody Brooks
cmbrooks@iastate.edu
CPRE 185 Section B
Programming Practice 2
<Reflection 1 What are you trying to learn or achieve?>
    This program was intended to practice using functions and using conditional
    statements. To do this, I designed a program where a user can guess a number
    between 1 and 10. The response of the program was different based on how
    the user's input compared to the secret number.
<Reflection 2 Were you successful? Why or why not?>
    Yes. The program correctly responds to the user based on the inputted guess.
    I successfully implemented a function I defined and several conditional
    statements so that I could get a range of response.
<Reflection 3 Would you do anything differently if you started the program over? If so, explain what.>
    I would try harder to get a new random number every time the prigram runs.
    Along with this, adding the functionality to change the range of the secret
    number. For example, instead of guessing a number between 1 and 10, perhaps
    guessing a number between 12 and 68.
<Reflection 4 Think about the most important thing you learned when writing this piece of code. What was it and explain why it was significant.>
    Generating random numbers is a complex process compared to other languages
    like Java and Python. I was also reminded that the order of if/else if
    statements matters. I tried to check and see if the guess was within the
    correct range at the end, and when I tested it, the "Higher" or "Lower"
    conditionals triggered first.
*/

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
        if (guess > 10 && guess < 1) {
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
