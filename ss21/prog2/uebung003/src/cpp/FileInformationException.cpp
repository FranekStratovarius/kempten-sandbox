#include "FileInformationException.h"

FileInformationException::FileInformationException(std::string imessage,int ilength, std::string ifilename, std::string ifileinfo) : std::logic_error(imessage){
	message=imessage;
	length=ilength;
	filename=ifilename;
	fileinfo=ifileinfo;
}
