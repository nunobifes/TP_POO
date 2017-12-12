#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

#include "Consola.h"

//Quando tiverem prontas incluir a classe Formigas, Comunidade e Ninhos

using namespace std;

class mundo {
	char cenas;
	
	//ninho* ni;
	//formigas* form;
	//comunidade* com;
public:
	mundo();

	int getCenas() { return cenas; }
	void setCenas(char c);

	//comunidade* getComunidade() {return com;}
	//ninho* getNinho() {return ni;}
	//formiga* getFormiga() {return form;}

	//void setNinho(ninho* ni);
	//void setFormiga(formigas* form);
	//void setComunidade(comunidade* com);

	~mundo();

	
};



