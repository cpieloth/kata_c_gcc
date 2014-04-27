/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include <stdio.h> // printf()
#include "http.h"

int http_open(const char* url, int port)
{
    printf("http_open() called!\n");
    return 1;
}

void http_close(int handle)
{
    printf("http_close() called!\n");
}
