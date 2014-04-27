/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include <stdio.h> // printf()
#include "http.h"

int open(const char* url, int port)
{
    printf("http::open() called!\n");
    return 1;
}

void close(int handle)
{
    printf("http::close() called!\n");
}
