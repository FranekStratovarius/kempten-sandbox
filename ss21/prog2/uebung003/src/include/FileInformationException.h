#include <stdexcept>
#include <string>

class FileInformationException : public std::logic_error{
	public:
		FileInformationException(std::string message,int length, std::string filename, std::string fileinfo);
		std::string message;
		int length;
		std::string filename;
		std::string fileinfo;
};
