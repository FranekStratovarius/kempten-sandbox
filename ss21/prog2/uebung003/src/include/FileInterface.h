#pragma once
#include <string>

using namespace std;

class FileInterface {


public:

	/**
	* Returns true if and only if the file with the given name exists.
	*/
	static bool fileExists(string fileName);
	/**
	* Returns the size of the given file if it exists and is not a directory.
	* Throws a FileException, otherwise.
	*/
	static unsigned long long getSize(string fileName);
	/**
	* Returns true if and only if the given file is a directory.
	* Throws a FileException if it does not exist.
	*/
	static bool isDirectory(string fileName);
	/**
	* Returns the content of the directory given by dirName as a list of paths to files 
	* in an array of strings. Note, that memory is allocated for this array, that
	* has to be freed eventually.
	* Throws a FileException if a file with name dirName it does not exist or is not 
	* a directory.
	*/
	static string* getContentOfDirectory(string dirName, int& size);
	/**
	* Returns the number of files (data-files and directories) contained in
	* the directory given by dirName.
	* Throws a FileException if a file with name dirName it does not exist or is not
	* a directory.
	*/
	static int getNumberOfFilesInDir(string dirName);
	/**
	* Returns the name of a file without path given a path of a file.
	* Example: If fileName = "c:/someDir/anotherDir/file.txt" then the
	* function returns "file.txt".
	*/
	static string getFileNameNoPath(string fileName);
	/**
	* Reads the content of the file with the given fileName to a string,
	* that is returned.
	* Throws a FileException if a file with name fileName it does not exist or is 
	* a directory. Also throws FileExceptions if the file coult not be read
	* or the reading fails for some reason.
	*/
	static string readTextFile(string fileName);

};

