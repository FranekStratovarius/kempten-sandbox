#include <string>

class FileCommander{
	public:
		static int getDisplayedSize(unsigned long long size);
		static std::string getUnitName(unsigned long long size);
		static std::string getPoints(int nrOfPoints);
		static std::string getShortInfo(std::string fileName, unsigned int len);
		static unsigned long long listFiles(std::string dir, unsigned int screenCharWidth);
		static unsigned long long listFilesRecursively(std::string dir, unsigned int screenCharWidth);
};
