#include "bib.h"

const int anzZitate=4;
zitat zitate[anzZitate]={
	{
		"BlaBluBlubb",
		"Irgendwer",
		"Unbekanntes",
		2020
	},
	{
		"Der Tod ist das Solideste, was das Leben bisher erfunden hat."
		"Émile","Michel Cioran",
		0
	},
	{
		"Wir leben alle unter dem gleichen Himmel, aber wir haben nicht alle den gleichen Horizont.",
		"Konrad","Adenauer",
		0
	},
	{
		"Das Leben ist eine Illusion, hervorgerufen durch Alkoholmangel.",
		"Charles","Bukovski",
		0
	},
};

int getMaxZitate(){
	return anzZitate;
}

zitat getZitat(int welches){
	if(welches<0||welches>anzZitate-1){
		zitat ret={
			"ERROR",
			"ERROR",
			"ERROR",
			0
		};
		return ret;
	}	
	return zitate[welches];
}
