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

	// modulo
    int dividend = 8;
    int divisor = 3;
	int mod = modulo(dividend, divisor);
	printf("%d mod %d = %d\n", dividend, divisor, mod);

	return EXIT_SUCCESS;
}
