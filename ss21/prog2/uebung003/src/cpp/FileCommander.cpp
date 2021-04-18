#include <cmath>
#include <climits>
#include <string>
#include <stdexcept>
#include <iostream>

#include "FileCommander.h"
#include "FileInterface.h"
#include "FileException.h"
#include "FileInformationException.h"

int FileCommander::getDisplayedSize(unsigned long long size){
	int magnitude=0;
	while(size/pow(1024,magnitude)>1024){	//1024^k so lange erhöhen bis size rein passt
		magnitude++;
	}
	return size/pow(1024,magnitude);
}

std::string FileCommander::getUnitName(unsigned long long size){
	int magnitude=0;
	while(size/pow(1024,magnitude)>1024){	//gleiches wie getDisplayedSize nur dass dieses mal nicht die angepasste größe, sondern die größenordnung zurückgegeben wird
		magnitude++;
	}
	switch(magnitude){
		case 0: return "Byte";
		case 1: return "KiB";
		case 2: return "MiB";
		case 3: return "GiB";
		case 4: return "TiB";
		case 5: return "PiB";
		case 6: return "EiB";
		case 7: return "ZiB";
		case 8: return "YiB";
		default: return "zu faul für weitere Einträge";
	}
}

std::string FileCommander::getPoints(int nrOfPoints){
	if(nrOfPoints<0){	//fehler abfangen
		throw std::logic_error("Number of points "+std::to_string(nrOfPoints)+" negative, can't draw that...");
	}
	std::string points="";
	for(int i=0;i<nrOfPoints;i++){	//über punktanzahl loopen
		points+=".";	//punkte aneinander kleben
	}
	return points;
}

std::string FileCommander::getShortInfo(std::string fileName, unsigned int len){
	if(FileInterface::fileExists(fileName)){	//check ob das element existiert
		if(FileInterface::isDirectory(fileName)){	//check ob element ordner ist
			std::string name=FileInterface::getFileNameNoPath(fileName);	//ordnername ohne rest von pfad bekommen
			int nrOfPoints=len-name.length()-5;	//punkteantahl ausrechnen
			if(nrOfPoints<0){	//FEHLER schreien wenn zu wenig platz
				throw FileInformationException("Length of Filename '"+name+"' and '<DIR>' is longer than "+std::to_string(len)+".",len,fileName,"<DIR>");
			}else{	//string mit ordnername, punkten und <DIR> zurückgeben
				return name+FileCommander::getPoints(nrOfPoints)+"<DIR>";
			}
		}else{	//element ist datei
			std::string name=FileInterface::getFileNameNoPath(fileName);	//dateiname ohne rest von pfad bekommen
			int filesize=FileInterface::getSize(fileName);	//größe rausfinden
			std::string size=std::to_string(FileCommander::getDisplayedSize(filesize))+" "+FileCommander::getUnitName(filesize);	//größe lesbar mit einheit formatieren
			int nrOfPoints=len-name.length()-size.length();	//punkteantahl ausrechnen
			if(nrOfPoints<0){	//FEHLER schreien wenn zu wenig platz ist
				throw FileInformationException("Length of Filename '"+name+"' and '"+size+"' is longer than "+std::to_string(len)+".",len,fileName,size);
			}else{	//string mit dateiname, punkten und lesbarer größe zurückgeben
				return name+FileCommander::getPoints(nrOfPoints)+size;
			}
		}
	}else{	//FEHLER schreien
		throw FileException("Datei oder Verzeichnis "+fileName+" existiert nicht.");
	}
}

unsigned long long FileCommander::listFiles(std::string dir, unsigned int screenCharWidth){
	int size;	//size of contentlist
	int totalsize=0;	//totalsize of files
	std::string* list=FileInterface::getContentOfDirectory(dir,size);	//get content of folder in dir
	std::cout<<"Content of "+dir+":\n";	//print titel
	for(int i=0;i<size;i++){	//loop through items in contentlist
		if(!FileInterface::isDirectory(list[i])){	//check if content is file
			try{
				std::cout << FileCommander::getShortInfo(list[i],screenCharWidth) << "\n";	//try printing fileinfo
				totalsize+=FileInterface::getSize(list[i]);	//sum filesizes
			}catch(FileInformationException fie){
				std::cout << "Error: Info too long\n";	//shout ERROR
			}
		}
	}
	for(int i=0;i<size;i++){	//loop through items in contentlist
		if(FileInterface::isDirectory(list[i])){	//check if content is dir
			try{
				std::cout << FileCommander::getShortInfo(list[i],screenCharWidth) << "\n";	//try printing dirinfo
			}catch(FileInformationException fie){
				std::cout << "Error: Info too long\n";	//shout ERROR
			}
		}
	}
	std::cout << "Total size: "+std::to_string(FileCommander::getDisplayedSize(totalsize))+" "+FileCommander::getUnitName(totalsize)+"\n";	//print total size of files in directory
	return totalsize;
}

unsigned long long FileCommander::listFilesRecursively(std::string dir, unsigned int screenCharWidth){
	int size;	//size of contentlist
	int totalsize=0;	//totalsize of files
	std::string* list=FileInterface::getContentOfDirectory(dir,size);	//get content of folder in dir
	totalsize+=FileCommander::listFiles(dir,screenCharWidth);	//print content of current folder and sum totalsize
	for(int i=0;i<size;i++){	//loop through items in contentlist
		if(FileInterface::isDirectory(list[i])){	//check if content is dir
			totalsize+=FileCommander::listFilesRecursively(list[i],screenCharWidth);	//recursive call of subfolders
		}
	}
	return totalsize;
}

