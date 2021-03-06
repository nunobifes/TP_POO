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
	Comunidade *cGuerra;
	int cor;
	int id;
	vector<Formiga*> form;
	

public:
	Comunidade(Mundo* m, int cor);
	Comunidade(Comunidade& c);
	Comunidade& operator=(const Comunidade& co);
	void setGuerra(Comunidade* g);
	Comunidade* get_guerra() const;
	//Comunidade(Ninho *id, Ninho *cor);

	

	Ninho* get_ninho() { return ni; }
	vector<Formiga*> get_formiga() { return form; }

	int get_cor() const;
	int get_id() const;
	
	void avanca(Mundo* m);

	//	void setEnergiaNinho(Mundo* m, int energia);
	//void setNinho(Ninho* ni);
	static void reset_id();
	void modoPaz();
	void add_formiga(int lim, char t, int x, int y);
	void mata_formiga(int x, int y);
	//void comeu_migalha(Mundo* m);
	//void setFormiga(Formiga* form);
	string lista_info() const;

	~Comunidade();



};
#endif