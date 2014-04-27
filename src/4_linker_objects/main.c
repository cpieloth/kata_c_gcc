/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h> // printf()

#include "calculator.h"

int main()
{
    // sum
    int summand1 = 23;
    int summand2 = 42;
    int sum = add(summand1, summand2);
    printf("%d + %d = %d\n", summand1, summand2, sum);

    // difference
    int minuend = 42;
    int subtrahend = 23;
    int diff = sub(minuend, subtrahend);
    printf("%d - %d = %d\n", minuend, subtrahend, diff);

    // division (integer)
    int dividend = 8;
    int divisor = 3;
    DivT div = division(dividend, divisor);
    printf("%d div %d = %d (remainder: %d)\n", dividend, divisor, div.quotient, div.remainder);

    return EXIT_SUCCESS;
}
