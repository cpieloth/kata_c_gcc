/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/**
 * Adds a and b.
 *
 * \param a summand
 * \param b summand
 * \return sum of a+b
 */
int add(int a, int b);

/**
 * Subtracts a and b.
 *
 * \param a minuend
 * \param b subtrahend
 * \return difference of a-b
 */
int sub(int a, int b);

/**
 * Structure for integer division.
 */
typedef struct div
{
    int quotient; /**< Quotient of division */
    int remainder; /**< Remainder of division */
} DivT;

/**
 * Integer division.
 *
 * \param a dividend
 * \param b divisor
 * \return quotient and remainder
 */
DivT division(int a, int b);

#endif /* CALCULATOR_H_ */
