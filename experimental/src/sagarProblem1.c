/*
Initial deposite: $1000
Interest compounds monthly
Interest is 1% per month
Compute monthly ballance for each year (for 10 years)
*/

#include <stdio.h>
#include <math.h>

int main () {

    double initialDeposite, interest, ballance;
    int compoundsPerYear, years;

    printf("Enter the initial deposite:\n");
    scanf("%lf", &initialDeposite);

    printf("Enter the number of compounds per year:\n");
    scanf("%d", &compoundsPerYear);

    printf("Enter the annual interest:\n");
    scanf("%lf", &interest);

    printf("Enter the number of years:\n");
    scanf("%d", &years);

    for (int currentYear = 0; currentYear <= years; currentYear++){
        ballance = (initialDeposite * pow((1 + (interest / compoundsPerYear)), (compoundsPerYear * currentYear)));
        printf("Year %d ballance: %.2lf\n", currentYear, ballance);
    }

    return 0;

}
