#include <cstdio>	//for printf
#include <string>	//for std::stoi (conversion from string to int for calling arguments)
#include <iostream>	//for cin cout
#include <sys/ioctl.h>	//[linux] for get terminalsize
#include <filesystem>	//for absolute filepath

#include "FileCommander.h"
#include "FileInterface.h"
#include "FileException.h"

int main(int argc,char* argv[]){
	/*
	*	TESTS
	*/

	/*
	*	#1
	*/

	/*
	//a) and b) with get size and name
	unsigned long long size=2715273;
	std::cout << FileCommander::getDisplayedSize(size) << " " << FileCommander::getUnitName(size) << std::endl;
	size=637;
	std::cout << FileCommander::getDisplayedSize(size) << " " << FileCommander::getUnitName(size) << std::endl;
	size=26155;
	std::cout << FileCommander::getDisplayedSize(size) << " " << FileCommander::getUnitName(size) << std::endl;
	size=18446744073709551615;
	std::cout << FileCommander::getDisplayedSize(size) << " " << FileCommander::getUnitName(size) << std::endl;
	//provoke error
	//size=18446744073709551616;
	//std::cout << fico->getDisplayedSize(size) << " " << fico->getUnitName(size) << std::endl;
	*/

	/*
	*	#2
	*/

	/*
	std::cout << FileCommander::getPoints(10) << std::endl;
	//provoke error
	//std::cout << fico->getPoints(-10) << "\n";
	*/

	/*
	*	#3
	*/

	/*
	std::cout << FileCommander::getShortInfo("Beispielverzeichnis/Bilder",30) << std::endl;
	std::cout << FileCommander::getShortInfo("Beispielverzeichnis/alterSchrott.bin",30) << std::endl;
	//provoke error
	//std::cout << FileCommander::getShortInfo("Beispielverzeichnis/alterSchrott.bin",10) << std:::endl;
	*/

	/*
	*	#5
	*/

	/*
	FileCommander::listFiles("Beispielverzeichnis/Bilder",40);
	FileCommander::listFiles("Beispielverzeichnis/Briefe",40);
	*/

	/*
	*	#6
	*/

	/*
	unsigned long long filesize=FileCommander::listFilesRecursively("Beispielverzeichnis",wsize.ws_col);
	std::cout << "Total length of all files in all subdirectories: " << FileCommander::getDisplayedSize(filesize) << " " << FileCommander::getUnitName(filesize) << std::endl;
	*/

	/*
	*	#7
	*/

	int textwidth=100;
	struct winsize wsize;	//[linux]
	ioctl( 0, TIOCGWINSZ, (char *) &wsize );	//[linux] get size of terminal
	textwidth=wsize.ws_col;	//[linux]
	std::string dir="Beispielverzeichnis";	//Startverzeichnis hardcoded
	if(argc>1){
		dir=std::filesystem::absolute(argv[1]);	//[linux?] absolutes Startverzeichnis bekommen, kann auf windows ggf nicht funktionieren
	}
	while(true){
		std::string input;
		std::cout << dir << ": ";	//print currend dir
		std::cin >> input;	//get input command
		ioctl( 0, TIOCGWINSZ, (char *) &wsize );	//[linux] look for change in terminalsize
		if(input=="dir"){	//list content of current dir
			FileCommander::listFiles(dir,textwidth);
		}else if(input=="dirr"){	//list content of current dir recursively
			unsigned long long filesize=FileCommander::listFilesRecursively(dir,textwidth);	//start recursion and get totalsize
			std::cout << "Total length of all files in all subdirectories: " << FileCommander::getDisplayedSize(filesize) << " " << FileCommander::getUnitName(filesize) << std::endl;	//print total size
		}else if(input=="view"){	//view file
			std::string targetfile;
			std::cin >> targetfile;	//get filename
			try{
				std::cout << FileInterface::readTextFile(dir+"/"+targetfile) << std::endl;	//read file and print it
			}catch(FileException fex){	//catch exception if file doesn't exist
				std::cout << fex.what() << std::endl;
			}
		}else if(input=="cd"){	//change directory
			std::string targetdir;
			std::cin >> targetdir;	//get targetdirectory
			if(targetdir==".."){	//up one dir
				if(dir.rfind("/")<0||dir.rfind("/")>=dir.length()){	//check if it is possible to go up
					std::cout << "can't go up" << std::endl;	//errormessage
				}else{
					dir.erase(dir.rfind("/"),dir.length()-1);	//remove last dir from path
				}
			}else if(FileInterface::isDirectory(dir+"/"+targetdir)){	//check if targetdir id actual dir
				dir+="/"+targetdir;	//add targetdir to path
			}
		}else if(input=="quit"){	//quit command
			break;	//break while loop
		}
	}
	return 0;
}
