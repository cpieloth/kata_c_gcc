/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include "calculator.h"

int add(int a, int b)
{
    return a + b;
}

DivT division(int a, int b)
{
    DivT result;
    result.quotient = a / b;
    result.remainder = a % b;
    return result;
}
