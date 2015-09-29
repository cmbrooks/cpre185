/*
	Cody Brooks
	cmbrooks@iastate.edu
	CprE 185 B
	Programming Practice 1
        <Reflection 1 What were you trying to learn or achieve?>
		The goal was to practice writing functions and calling them from the main function. I chose to write three functions 	hose purpose was to add, subtract and multiply two numbers the user inputs.
        <Reflection 2 Were you successful? Why or Why not?>
		Yes, I was successsful. I was able to write all three of my intended functions and call them from the main function. My functions behave as expected and the program compiled successfuly.
	<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
		I would not do anything differently.
	<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
		I was reminded that the scanf() function requires primitive variables to use the ampersand in front of the variable name. It was good to see the program not work and then finding that it was an improper use of scanf() and then writing it correctly for the rest of the program.
*/

#include <stdio.h>

//Adds two numbers
int add (int a, int b) {

	return a + b;

}

//Subtracts two numbers
int subtract (int a, int b) {

	return a - b;

}

//Multiplies two numbers
int multiply (int a, int b) {

	return a * b;

}

int main () {
	
	int a;
	int b;
	
	//Uses the add function
	printf("Enter two numbers to add (ints seperated by commas):");
	scanf("%d,%d", &a, &b);
	printf("%d + %d = %d\n", a, b, add(a,b));
	
	//Uses the subtract function
	printf("Enter two numbers to subtract (ints seperated by commas):");
	scanf("%d,%d", &a, &b);
	printf("%d - %d = %d\n", a, b, subtract(a,b));

	//Uses the multiply function
	printf("Enter two numbers to multiply (ints seperated by commas):");
	scanf("%d,%d", &a, &b);
	printf("%d * %d = %d\n", a, b, multiply(a,b));

	return 0;

}
	
