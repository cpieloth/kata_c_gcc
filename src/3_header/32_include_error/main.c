/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h> // printf()

#include "algorithm.h"
#include "calculator.h"

int main()
{
    // sum
    int summand1 = 23;
    int summand2 = 42;
    int sum = add(summand1, summand2);
    printf("%d + %d = %d\n", summand1, summand2, sum);

    // division (integer)
    int dividend = 8;
    int divisor = 3;
    DivT div = division(dividend, divisor);
    printf("%d div %d = %d (remainder: %d)\n", dividend, divisor, div.quotient, div.remainder);

    // division (double)
    double dividend_dbl = 13;
    double divisor_dbl = 5;
    DivT div_dbl = division_double(dividend_dbl, divisor_dbl);
    printf("%f div %f = %d (remainder: %d)\n", dividend_dbl, divisor_dbl, div_dbl.quotient, div_dbl.remainder);

    // algorithm
    double a = 8;
    double b = 3;
    double f = formula(a, b);
    printf("(%f + %f) + (%f mod %f)= %f\n", a, b, a, b, f);

    return EXIT_SUCCESS;
}
