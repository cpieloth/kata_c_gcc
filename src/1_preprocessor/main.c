/**
 * Introduction into C preprocessor: comments, defines, header
 *
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h> // printf()

#ifndef NDEBUG
    #define LOG_DEBUG(arg)   logDebug(arg)
#else
    #define LOG_DEBUG(arg)   printf(">>> LOG_DEBUG() call removed!\n")
#endif

#define VAR_DEFAULT 42

/**
 * Logs a debug message to stdout.
 *
 * \param msg C-String to log.
 */
void logDebug(const char* const msg)
{
    printf("[DEBUG] %s\n", msg);
}

int main(int argc, const char* argv[])
{
    // This comment and all other comments are removed by the C preprocessor.

    // Defines are replaced by the C preprocessor
    int var = VAR_DEFAULT;
    printf("var = %d\n", var);

    // Macros are interpreted and replaced by the C preprocessor.
    LOG_DEBUG("LOG_DEBUG() called!");
    logDebug("logDebug() called!");

    return EXIT_SUCCESS;
}
