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
	static int conta;
	
	int cor;
	int id;
	vector<Formiga*> form;
	

public:
	Comunidade(Mundo* m, int cor);
	//Comunidade(Ninho *id, Ninho *cor);

	

	Ninho* get_ninho() { return ni; }
	vector<Formiga*> get_formiga() { return form; }

	int get_cor() const;
	int get_id() const;

//	void setEnergiaNinho(Mundo* m, int energia);
	//void setNinho(Ninho* ni);
	static void reset_id();
	void add_formiga(int lim, char t, int x, int y);
	void mata_formiga(int x, int y);
	//void setFormiga(Formiga* form);
	string lista_info() const;

	~Comunidade();


};
#endif