#include <stdio.h>
#include <math.h>

int main () {

    /* Correct */
    int a;
    a = 6427 + 1725;
    printf("a: 6427 + 1725 = %d\n", a);

    /* Correct */
    int b;
    b = (6971 * 3925) - 95;
    printf("b: (6971 * 3925) - 95 = %d\n", b);

    /*
    Integer Division
    -- Changed
    */
    double c;
    c = 79 + 12 / 5;
    printf("c: 79 + 12 / 5 = %.2lf\n", c);

	/* Correct */
    double d;
    d = 3640.0 / 107.9;
    printf("d: 3640.0 / 107.9 = %.2lf\n", d);

	/*
	Integer Division, incorrect data-type for e
	-- Changed '(22 / 3)' to '(22.0 / 3.0)'
	-- Changed 'int e' to 'double e'
	-- Changed '%d' to '%.2lf'
	*/
    double e;
    e = (22.0 / 3.0) * 3;
    printf("e: (22.0 / 3.0) * 3 = %.2lf\n", e);

	/*
	Integer Division, incorrect data-type for f
	-- Changed '22 / (3 * 3)' to '22.0 / (3 * 3)'
	-- Changed 'int f' to 'double f'
	-- Changed '%d' to '%.2lf'
	*/
    double f;
    f = 22.0 / (3 * 3);
    printf("f: 22 / (3 * 3) = %.2lf\n", f);

	/*
	Integer division
	-- Changed '33 / (3 * 3)' to '33.0 / (3 * 3); 
	*/
    double g;
    g = 33 / (3 * 3);
    printf("g: 33 / (3 * 3) = %.2lf\n", g);

	/*
	Integer Division, order of opperations
	-- Changed '22 / 3 * 3' to '22.0 / (3 * 3)'
	*/
    double h;
    h = 22.0 / (3 * 3);
    printf("h: 22 / 3 * 3 = %.2lf\n", h);

	/* Correct */
    double i;
    i = (22.0 / 3) * 3.0;
    printf("i: (22.0 / 3) * 3.0 = %.2lf\n", i);

	/*
	Incorrect data-type
	-- Changed 'int j' to 'double j'
	-- Changed '%d' to '%.2lf'
	*/
    double j;
    j = 22.0 / (3 * 3.0);
    printf("j: 22.0 / (3 * 3.0) = %.2lf\n", j);

	/*
	Order of opperations
	-- Changed '22.0 / 3.0 * 3.0' to '22.0 / (3.0 * 3.0)'
	*/
    double k;
    k = 22.0 / (3.0 * 3.0);
    printf("k: 22.0 / 3.0 * 3.0 = %.2lf\n", k);

	/* Correct */
    double area;
    area = pow((23.567 / (2 * M_PI)), 2) * M_PI;
    printf("l: area of %.2lf\n", area);

	/* Correct */
    double meters;
    meters = 14 * 0.3048;
    printf("m: 14ft = %.2lfm\n", meters);

	/* Correct */
    double celsius;
    celsius = (76 - 32) / 1.8;
    printf("n: 76F = %.2lfC\n", celsius);

    return 0;

}
