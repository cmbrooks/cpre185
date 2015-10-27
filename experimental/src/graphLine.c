#include <stdio.h>

void print_chars(int num, char use) {
	int i;
	for (i = 0; i < num; i++) {
		printf("%c", use);
	}
}

void graph_line(int number) {
	char printChar;
	if (number == 0){
		printf("0\n");
	} else if (number > 0) {
        print_chars(40, ' ');
        print_chars(abs(number), 'r');
        printf("\n");
	} else {
	    print_chars(40-abs(number), ' ');
	    print_chars(abs(number), 'l');
        printf("\n");
	}
}

int main () {

    graph_line(-5);
    graph_line(10);

    return 0;

}
