#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define TANKW 60
#define TANKH 20
#define MAXSHARKS 30
#define LOOPALL for (y=0; y<TANKH; y++) { for (x=0; x<TANKW; x++) {

int sign(int x){
	if (x>0) return 1;
	if (x<0) return -1;
	return 0;
	}
// adapted from Bresenham wikipedia page
void drawLine(char laser, int x1, int y1, int x2, int y2, char tank[TANKW][TANKH]) {
        int x = x1;
        int y = y1;
        double deltaX = x2-x1;
	int sx = -1;
	if (deltaX >0) sx = 1;
        double deltaY = y2-y1;
        double error =0;
	if (y2 == y1) {
		for (x=x1; x!=x2; x = x + sx) {
			 tank[x][y1] = laser;
			}
		return;
		}

	double deltaError = abs(deltaY/deltaX);
	for (x= x1; x<=x2; x++) {
		tank[x][y] = laser;
		error = error + deltaError;
		while (error >=0.5){
	                tank[x][y] = laser;
			y= y + sign(y2-y1);
			error = error -1;
			}
		}

	}


void outputTank(char tank[TANKW][TANKH]) {
	// clear terminal
	char clear[] = {27, '[', 'H', 27, '[', '2', 'J', '\0'};
	int x, y;
	puts(clear);

		LOOPALL
				printf("%c", tank[x][y]);
			}
			printf("\n");
		}
	}

int swim(int numSharks, int sharkX[], int sharkY[], char tank[TANKW][TANKH], int mrPowersX, int mrPowersY, char sLetter[]) {
	int i;
	for (i = 0; i < numSharks; i++) {

		tank[sharkX[i]] [sharkY[i]] = '.' ;
		int xMove = rand() %3  -1;
		int yMove = rand() %3 -1;

		sharkX[i] += xMove;
		sharkY[i] += yMove;
		sharkX[i] = (sharkX[i] + TANKW) % TANKW;
		sharkY[i] = (sharkY[i] + TANKH) % TANKH;
		tank[sharkX[i]] [sharkY[i]] = sLetter[i];
		}

	}

void mywait(int x) {
	int i,j;
	for (i = 0; i< 100000; i++) {
		for (j=0; j< x; j++) {
			}
		}
	}


// command line is numSharks Followed by their names.
int main(int argc, char* argv[]) {
	int numSharks;
	int mrPowersX = TANKW/2;
	int mrPowersY = TANKH/2;
	int x,y,i;
	char tank[TANKW][TANKH];
	int sharkX[MAXSHARKS];
	int sharkY[MAXSHARKS];
	char sharkLetters[MAXSHARKS];
	// Water looks like "Periods".... right....
	LOOPALL
		tank[x][y] = '.';
		}
	}

	tank[mrPowersX][mrPowersY] = 'A'; // that pesky Mr Powers is in the middle of the tank

	numSharks = atoi(argv[1]); // How many friggin' sharks

	for (i=0; i< numSharks; i++) {
		sharkX[i] = rand() % TANKW;
		sharkY[i] =  rand() % TANKH;
		tank[sharkX[i]][sharkY[i]] = argv[i+2][0]; // the friggin shark's first initial
		sharkLetters[i] = argv[2+i][0];
		}

	while (1) {
		outputTank(tank);
		fflush(stdout);
		mywait(1000);
		swim(numSharks, sharkX, sharkY, tank, mrPowersX, mrPowersY, sharkLetters);
		}


	}
