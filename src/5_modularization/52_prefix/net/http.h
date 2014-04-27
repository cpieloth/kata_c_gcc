/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#ifndef HTTP_H_
#define HTTP_H_

/**
 * Opens a connection to a HTTP server.
 *
 * \param url URL of the host
 * \param port Port of the service
 * \return Connection handle ID, error: -1
 */
int http_open(const char* url, int port);

/**
 * Closes a connection to a HTTP server.
 *
 * \param handle Connection handle ID
 */
void http_close(int handle);

#endif /* HTTP_H_ */
