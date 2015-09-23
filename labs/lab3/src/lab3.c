// CprE 185: Lab 3
// Problem 1: Mysterious Output

#include <stdio.h>

int main()
{
	int integerResult;
	double decimalResult;

	/*
	1. integerResult is an int, but a double value is assigned to it
		--Solution: Changed 'integerResult' to decimalResult
	2. Integer division
		--Solution: Chagnged 77/5 to 77.0/5.0
	*/
	decimalResult = 77.0 / 5.0;
	printf("The value of 77/5 is %lf\n", decimalResult);


	/*
	There is no value after the string to
	be displayed in the place of %d
		--Solution: Chagnged printf("..%d", ); to printf("..%d", integerResult);
	*/
	integerResult = 2 + 3;
	printf("The value of 2+3 is %d\n", integerResult);

	/*
	The integer formatter %d is used for a double value
		--Solution: Changed %d to %lf
	*/
	decimalResult = 1.0 / 22.0;
	printf("The value 1.0/22.0 is %lf\n", decimalResult);

	return 0;
}
