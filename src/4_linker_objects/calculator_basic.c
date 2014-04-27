/**
 * Implementation of calculator.h using basic +1 and -1 operations (++/--).
 *
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include <stdio.h> // printf()
#include "calculator.h"

int add(int a, int b)
{
    printf("calculator_basic::add() called!\n");
    int sum = a;
    int i;
    for (i = 0; i < b; ++i)
    {
        ++sum;
    }
    return sum;
}

int sub(int a, int b)
{
    printf("calculator_basic::sub() called!\n");
    int diff = a;
    int i;
    for (i = 0; i < b; ++i)
    {
        --diff;
    }
    return diff;
}

DivT division(int a, int b)
{
    printf("calculator_basic::division() called!\n");
    DivT result;
    result.quotient = 0;
    result.remainder = a;

    while (result.remainder > 0)
    {
        result.remainder = sub(result.remainder, b);
        ++result.quotient;
    }

    if (result.remainder < 0)
    {
        result.remainder = add(result.remainder, b);
        --result.quotient;

    }

    return result;
}
