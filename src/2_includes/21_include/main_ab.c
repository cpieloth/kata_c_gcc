/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include "calculator_a.c"
#include "calculator_b.c" // Error: Redefinition of "add"

int main()
{
    int sum = add(23, 42);
    return 0;
}
