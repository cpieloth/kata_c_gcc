/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include "calculator_a.c" // NOTE: Including source files is a bad practice in most situations.
#include "calculator_b.c" // Error: Redefinition of "add"

int main()
{
    int sum = add(23, 42);
    return 0;
}
