/**
 * Implementation of calculator.h using standard C operators.
 *
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include <stdio.h> // printf()
#include "calculator.h"

int add(int a, int b)
{
    printf("calculator_std::add() called!\n");
    return a + b;
}

int sub(int a, int b)
{
    printf("calculator_std::sub() called!\n");
    return a - b;
}

DivT division(int a, int b)
{
    printf("calculator_std::division() called!\n");
    DivT result;
    result.quotient = a / b;
    result.remainder = a % b;
    return result;
}
