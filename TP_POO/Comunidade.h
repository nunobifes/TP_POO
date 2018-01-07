#ifndef __COMUNIDADE__
#define __COMUNIDADE__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>

#include "Ninho.h"
#include "Formiga.h"
#include "Mundo.h"

class Ninho;
class Formiga;
class Mundo;

using namespace std;


class Comunidade {
	Ninho* ni;
	int id;
	vector<Formiga*> form;
	

public:
	Comunidade(Mundo* m);
	//Comunidade(Ninho *id, Ninho *cor);

	Ninho* get_ninho() { return ni; }
	vector<Formiga*> get_formiga() { return form; }

//	void setEnergiaNinho(Mundo* m, int energia);
	//void setNinho(Ninho* ni);
	void add_formiga_at(char t, int x, int y);

	//void setFormiga(Formiga* form);




};
#endif