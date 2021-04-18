#pragma once
#include <string>
#include <stdexcept>

using namespace std;

/*
* changed errno_t to int
* https://stackoverflow.com/a/24207339
*/

class FileException : public runtime_error {
public:
	static const int msgBufSize = 256;
	FileException(string msg);
	FileException(int errorNumber);
private:	
	char msgBuf[msgBufSize];	
};

