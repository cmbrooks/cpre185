// lab7.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of explore data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_DOWN, int* Button_UP, int* Button_LEFT, int* Button_RIGHT);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the esplora in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the esplora in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main() {

	double x, y, z;							// magnitude values of x, y, and z accelerations
	int b_Up, b_Down, b_Left, b_Right;		// variables to hold the button statuses
	double roll_rad, pitch_rad;				// value of the roll measured in radians
	int scaled_value; 						// value of the roll adjusted to fit screen display
	int time, exit;
	enum ReadState {PITCH, ROLL}; // For Funzies
	enum ReadState currentState;

	//insert any beginning needed code here
	currentState = PITCH;
	do
	{
		// Get line of input
		exit = read_acc(&x, &y, &z, &time, &b_Down, &b_Up, &b_Left, &b_Right);

		// check for button input
		// switch between roll and pitch(up vs. down button)

		if (b_Left == 1) {
			break;
		} else if (b_Down) {
			if (currentState == PITCH) {
				currentState = ROLL;
			} else {
				currentState = PITCH;
			}
		}
		// calculate roll and pitch
		// Scale your output value
		if (currentState == PITCH) {
			pitch_rad = pitch(y);
			scaled_value = scaleRadsForScreen(pitch_rad);
		} else {
			roll_rad = roll(x);
			scaled_value = scaleRadsForScreen(roll_rad);
		}

		// Output your graph line
		graph_line(scaled_value);

	} while (!exit); // Modify to stop when left button is pressed

	fflush(stdout);
	return 0;

}


int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_DOWN, int* Button_UP, int* Button_LEFT, int* Button_RIGHT) {
	int poop1, poop2;
	scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", time, a_x, a_y, a_z, Button_DOWN, Button_UP, Button_LEFT, Button_RIGHT, &poop1, &poop2);
	if (*Button_LEFT == 1) {
		return 1;
	} else {
		return 0;
	}
}

double roll (double x_mag) {
	return asin(x_mag);
}

double pitch (double y_mag) {
	return asin(y_mag);
}

//TODO Needs testing @cody
int scaleRadsForScreen (double rad) {
	return (rad * (78.0 / PI));
}

void print_chars(int num, char use) {
	int i;
	for (i = 0; i < num; i++) {
		printf("%c", use);
	}
}

void graph_line(int number) {
	char printChar;
	if (number == 0){
        print_chars(40, ' ');
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
