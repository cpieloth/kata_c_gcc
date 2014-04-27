/**
 * \author cpieloth
 * \copyright GNU GPL v3
 */

#ifndef FTP_H_
#define FTP_H_

/**
 * Opens a connection to a FTP server.
 *
 * \param url URL of the host
 * \param port Port of the service
 * \return Connection handle ID, error: -1
 */
int ftp_open(const char* url, int port);

/**
 * Closes a connection to a FTP server.
 *
 * \param handle Connection handle ID
 */
void ftp_close(int handle);

#endif /* FTP_H_ */
