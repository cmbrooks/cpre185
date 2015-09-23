#include <stdio.h>
#include <math.h>

int main () {

    int a;
    a = 6427 + 1725;
    printf("a: 6427 + 1725 = %d\n", a);

    int b;
    b = (6971 * 3925) - 95;
    printf("b: (6971 * 3925) - 95 = %d\n", b);

    double c;
    c = 79 + 12 / 5;
    printf("c: 79 + 12 / 5 = %.2lf\n", c);

    double d;
    d = 3640.0 / 107.9;
    printf("d: 3640.0 / 107.9 = %.2lf\n", d);

    int e;
    e = (22 / 3) * 3;
    printf("e: (22 / 3) * 3 = %d\n", e);

    int f;
    f = 22 / (3 * 3);
    printf("f: 22 / (3 * 3) = %d\n", f);

    double g;
    g = 33 / (3 * 3);
    printf("g: 33 / (3 * 3) = %.2lf\n", g);

    double h;
    h = 22 / 3 * 3;
    printf("h: 22 / 3 * 3 = %.2lf\n", h);

    double i;
    i = (22.0 / 3) * 3.0;
    printf("i: (22.0 / 3) * 3.0 = %.2lf\n", i);

    int j;
    j = 22.0 / (3 * 3.0);
    printf("j: 22.0 / (3 * 3.0) = %d\n", j);

    double k;
    k = 22.0 / 3.0 * 3.0;
    printf("k: 22.0 / 3.0 * 3.0 = %.2lf\n", k);

    double area;
    area = pow((23.567 / (2 * M_PI)), 2) * M_PI;
    printf("l: area of %.2lf\n", area);

    double meters;
    meters = 14 * 0.3048;
    printf("m: 14ft = %.2lfm\n", meters);

    double celsius;
    celsius = (76 - 32) / 1.8;
    printf("n: 76F = %.2lfC\n", celsius);

    return 0;

}
