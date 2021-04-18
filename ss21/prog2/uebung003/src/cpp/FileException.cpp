#include "FileException.h"
//#include <errno.h>
#include <string.h>

/*
* changed errno_t to int
* https://stackoverflow.com/a/24207339
*/

FileException::FileException(string msg)
	: runtime_error(msg), msgBuf{} {}

/*
* https://www.cplusplus.com/reference/cstring/strerror/
*/
FileException::FileException(int errorNumber)
	: runtime_error(strerror(errorNumber)), msgBuf{} {}
