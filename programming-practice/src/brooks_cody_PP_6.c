/*
Cody Brooks
cmbrooks@iastate.edu
CPRE 185 Section B
Programming Practice 6

         <Reflection 1 What were you trying to learn or achieve?>
            I tried to write a program that parses a string that contains a
            quadratic equation and calculates its roots. I had to create several
            functions that contained parameters that were passed by pointers.
        <Reflection 2 Were you successful? Why or Why not?>
            I was successful. I was able to return the roots of the equation
            3x^2+x+5=6 correctly.
        <Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
            I would take some more time to extend the functionality available with
            parsing the equation string. I would like to add functionality that allows
            bigger than single digit coeficients and negative numbers.
        <Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
            The most important thing I learned while writing this code was the syntax
            of using pointers and references as well as functions that can return
            more than one value at a time using pass by pointer methods.

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
void parseEquation(char equation[], int size, int* y, int* a, int* b, int* c);
int indexOfNextSymbol(char equation[], int size, int start);
void findQuadraticRoots(int a, int b, int c, int y, double* firstRoot, double* secondRoot);
void printCharArray(char arr[], int size);

int main() {

    int y, a, b, c;
    double root1, root2;

    // Equation should follow the format ax^2+bx+c=y
    // y, a, b and c can only be single digit numbers for this program
    // Only addition operators are allowed for this program
    char equation[12] = "3x^2+1x+5=6";
    printf("Equation: %s\n", equation);

    parseEquation(equation, 12, &y, &a, &b, &c);
    printf("\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("y: %d\n", y);

    findQuadraticRoots(a, b, c, y, &root1, &root2);
    printf("\n");
    printf("First root: %lf\n", root1);
    printf("Second root: %lf\n", root2);

    return 0;

}

// Updates the variables A, B, C and Y based on the equation string
void parseEquation(char equation[], int size, int* y, int* a, int* b, int* c) {
    char ch;
    int symbolIndex = indexOfNextSymbol(equation, size, 1);
    *a = equation[0] - '0'; // Reads the first character in the equation and converts it to an integer
    int numSymbolsFound = 1;
    while (symbolIndex != -1) {
        int nextNumber = equation[symbolIndex+1] - '0'; // Converts the character representing a number to an integer
        if (numSymbolsFound == 1) {
            *b = nextNumber;
        } else if (numSymbolsFound == 2) {
            *c = nextNumber;
        } else if (numSymbolsFound == 3) {
            *y = nextNumber;
        }
        symbolIndex = indexOfNextSymbol(equation, size, symbolIndex);
        numSymbolsFound++;
    }
}

// Returns the index within the equation string at which the next symbol to the right of start
int indexOfNextSymbol(char equation[], int size, int start) {
    int i;
    char ch;
    for (i = start + 1; i < size ; i++) {
        ch = equation[i];
        if (ch == '=' || ch == '+' || ch == '-') {
            return i;
        }
    }
    return -1;
}

// Takes coeficients of a quadratic equation to solve for its roots, which are passed by pointers
void findQuadraticRoots(int a, int b, int c, int y, double* firstRoot, double* secondRoot) {
    *firstRoot = (-b + sqrt(pow(b, 2) - 4.0 * a * (c - y))) / (2.0 * a);
    *secondRoot = (-b - sqrt(pow(b, 2) - 4.0 * a * (c - y))) / (2.0 * a);
}

// Used for debugging
void printCharArray(char arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%c\n", arr[i]);
    }
}
