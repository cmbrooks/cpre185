#include <stdio.h>
#include <string.h>

#define MAXLINE 201

int main (int argc, char* argv[]) {

    int i;
    char aLine[MAXLINE];
    // Characters to remove are in argv[1]

    while (1) {
        fgets(aLine, MAXLINE, stdin); // use standard input
        printf("%s", aLine);
    }

    return 0;

}
