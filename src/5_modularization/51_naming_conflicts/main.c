/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h> // printf()

#include "net/ftp.h"
#include "net/http.h"

int main()
{
    // FTP connection
    char ftp_url[] = "ftp://example.com";
    int ftp_port = 21;
    int ftp_handle = open(ftp_url, ftp_port);
    if (ftp_handle > 0)
    {
        printf("FTP connection established.\n");
        // some code
        close(ftp_handle);
    }
    else
    {
        printf("Could not open FTP connection!\n");
    }

    // HTTP connection
    char http_url[] = "http://example.com";
    int http_port = 80;
    int http_handle = open(http_url, http_port);
    if (http_handle > 0)
    {
        printf("HTTP connection established.\n");
        // some code
        close(http_handle);
    }
    else
    {
        printf("Could not open HTTP connection!\n");
    }

    return EXIT_SUCCESS;
}
