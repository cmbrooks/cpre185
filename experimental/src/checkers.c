#include <stdio.h>

//void initializeBoard (char board[][], int boardLength);
//void printBoard (char board[][], int boardLength);

void initializeBoard (int boardLength, char board[][8]) {
    int i, j;
    for (i = 0; i < boardLength; i++) {
        for (j = 0; j < boardLength; j++) {
            if ((i + j) % 2 == 1) {
                if (j < 3) {
                    board[i][j] = 'r';
                } else if (j > boardLength - 3) {
                    board[i][j] = 'b';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void printBoard (int boardLength, char board[][8]) {
    int i, j;
    for (i = 0; i < boardLength; i++) {
        for (j = 0; j < boardLength; i++) {
            printf("%c");
        }
        printf("\n");
    }
}

int main () {

    char board[8][8];
    initializeBoard(board, 8);
    printBoard(board, 8);

    return 0;

}
