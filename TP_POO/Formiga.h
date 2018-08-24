#ifndef __FORMIGA__
#define __FORMIGA__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <windows.h>
#include <vector>


class Mundo;

using namespace std;

class Formiga {

	char tipo;
	int energia;
	int r_visao;
	int r_mov;
	int x, y;
	int lim_m;
	int e_base;
	int e;
	//Variação de energica, só com as migalhas

public:
	
	// CONSTRUTOR
	Formiga(int e, int rv, int rm, char t, int x, int y, int lim);
		
	// SET'S
	void set_tipo(char t);
	void set_posX(int x);
	void set_posY(int y);
	void set_energia(int e);

	// GET'S
	char get_tipo() const;
	int get_posX() const;
	int get_posY() const;
	int get_energia() const;
	int get_energiab() const;
	int get_visao() const;
	int get_move() const;
	

	// FUNCOES
	void anda();
	void contr_energia(int ener);
	void comeu_migalha(Mundo * m);
	string lista_info() const;

};

#endif