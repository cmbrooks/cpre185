/*
Cody Brooks
cmbrooks@iastate.edu
CPRE 185 Section B
Programming Practice 5
         <Reflection 1 What were you trying to learn or achieve?>
            I was trying to practice how to use 2D arrays with and within functions.
            I tried to learn things like how to propperly pass 2D arrays into functions and
            how to return them. I was successful in this, but I realized that there
            is still a lot left to learn.
        <Reflection 2 Were you successful? Why or Why not?>
            I was successful because I learned many different ways that GCC will accept
            2D arrays as parameters. I found that the most flexible way is to pass the
            dimensions of the array in as integers before the arrays themselves.
        <Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
            I might add more functions like multiplication and division. Other than that,
            I am content with the amount of functionality that I was able to get working.
        <Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
            The most imortant thing I learned was that you can use parametric variables
            that were declared before the current parametric variable in it's definition.
            This enabled me to pass the size of the 2D array into the function, and use
            those dimensions to define the arrays when they were passed into the function. 
*/

#include <stdio.h>

void matrixAdd (int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int resultMatrix[rows][cols]);
void matrixSubtract (int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int resultMatrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);

int main () {

    int rows = 2;
    int cols = 3;

    int matrix1[rows][cols] = {{0,1,2}, {9,8,7}};
    int matrix2[rows][cols] = {{6,5,4},{3,4,5}};
    int resultMatrix[rows][cols];

    printf("Matrix 1:\n");
    printMatrix(rows, cols, matrix1);
    printf("\nMatrix 2:\n");
    printMatrix(rows, cols, matrix2);

    printf("\nMatrix 1 + Matrix 2:\n");
    matrixAdd(rows, cols, matrix1, matrix2, resultMatrix);
    printMatrix(rows, cols, resultMatrix);

    printf("\nMatrix 1 - Matrix 2:\n");
    matrixSubtract(rows, cols, matrix1, matrix2, resultMatrix);
    printMatrix(rows, cols, resultMatrix);

    return 0;

}

void matrixAdd (int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int resultMatrix[rows][cols]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            resultMatrix[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void matrixSubtract (int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int resultMatrix[rows][cols]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            resultMatrix[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
