/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "calculator.h"

/**
 * Calculates (a + b) + (a mod b).
 *
 * \param a
 * \param b
 * \return a + b + (a mod b)
 */
double formula(double a, double b);

/**
 * Integer division (wrapper for type double).
 *
 * \param a dividend
 * \param b divisor
 * \return quotient and remainder
 */
DivT division_double(double a, double b);

#endif /* ALGORITHM_H_ */
