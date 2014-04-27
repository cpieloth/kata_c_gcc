/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include "calculator.h"
#include "algorithm.h"

/**
 * Calculates (a + b) + (a mod b).
 *
 * \param a
 * \param b
 * \return a + b + (a mod b)
 */
double formula(double a, double b)
{
    const int sum = add(a, b);
    DivT div = division_double(a, b);
    return sum + div.remainder;
}

DivT division_double(double a, double b)
{
    DivT div = division((int) a, (int) b);
    return div;
}
