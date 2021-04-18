#include "FileInterface.h"
#include "FileException.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream> 



using namespace std;


bool FileInterface::fileExists(string fileName) {
    return filesystem::exists(fileName);
}

unsigned long long FileInterface::getSize(string fileName) {
    if (filesystem::exists(fileName)) {
        if (!isDirectory(fileName)) {
            try {
                uintmax_t s = filesystem::file_size(fileName);
                return static_cast<unsigned long long>(s);
            } catch (filesystem::filesystem_error err) {
                throw FileException(err.what());
            }
        } else throw FileException("File " + fileName + " is a directory.");
    } else throw FileException("File " + fileName + " does not exist.");
}


bool FileInterface::isDirectory(string fileName) {
    if (filesystem::exists(fileName))
        return filesystem::is_directory(fileName);
    else throw FileException("File " + fileName + " does not exist.");
}


int FileInterface::getNumberOfFilesInDir(string dirName) {
    if (!isDirectory(dirName))
        throw FileException("File " + dirName + " is not a directory.");
    using filesystem::directory_iterator;
    return std::distance(directory_iterator(dirName), directory_iterator{});
}


string FileInterface::getFileNameNoPath(string fileName) {
    return filesystem::path(fileName).filename().string();
}


string FileInterface::readTextFile(string fileName) {
    if (!fileExists(fileName)) {
        throw FileException("File " + fileName + " does not exist.");
    }
    if (isDirectory(fileName)) {
        throw FileException("Cannot read " + fileName + " as it is a directory.");
    }
    unsigned long long realSize = getSize(fileName);
    if (realSize > numeric_limits<int>::max()) {
        throw FileException("Cannot read " + fileName + " because it has more than " + 
            to_string(numeric_limits<int>::max()) + " bytes.");
    }
    int size = static_cast<int>(getSize(fileName));
    ifstream fIn;
    fIn.exceptions(ios::badbit | ios::failbit);
    try {
        fIn.open(fileName, ios::in | ios::binary);
    } catch (exception exc) {
        if (fIn.is_open()) fIn.close();
        throw FileException("File " + fileName +
            " exists, but could not be opened for reading.\n" +
            "Cause: " + exc.what());
    }
    try {
        stringstream ss;
        static const int bufSize = 256;
        char buf[bufSize];
        buf[bufSize - 1] = 0;
        int remainingSize = size;
        while (remainingSize > 0) {
            fIn.read(buf, min(remainingSize, bufSize - 1));
            if (remainingSize < bufSize) buf[remainingSize] = 0;
            remainingSize -= min(remainingSize, bufSize - 1);
            ss << buf;
        }
        if (fIn.is_open()) fIn.close();
        return ss.str();
    } catch (exception exc) {
        throw FileException("Error while reading file " + fileName + ":\n" + exc.what());
    }
}


string* FileInterface::getContentOfDirectory(string dirName, int& size) {
    size = getNumberOfFilesInDir(dirName);
    string* content = new string[size];
    int i = 0;
    for (auto& f : filesystem::directory_iterator(dirName)) {     
        content[i] = string(f.path().string());;
        i++;
    }
    return content;
}



