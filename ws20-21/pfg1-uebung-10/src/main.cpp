#include <iostream>
#include "bib.h"

int main(){
	std::cout << "Bitte Nummer des gewünschten Zitats eingeben (0 bis " << getMaxZitate()-1 << "): ";
	int welches;
	std::cin >> welches;
	zitat meinZitat=getZitat(welches);
	std::cout << "\n";;
	std::cout << "Zitat: " << meinZitat.zitat << std::endl;
	std::cout << "Autor: " << meinZitat.autorNachname << ", " << meinZitat.autorVorname << std::endl;
	if(meinZitat.releasedate!=0)
		std::cout << "Jahr: " << meinZitat.releasedate << std::endl;
	return 0;
}
