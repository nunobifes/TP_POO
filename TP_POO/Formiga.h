#ifndef __FORMIGA__
#define __FORMIGA__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <windows.h>
#include <vector>

#include "Cuidadora.h"
#include "Vigilante.h"
#include "Assaltante.h"
#include "Exploradora.h"


using namespace std;

class Formiga {

	char tipo;
	int energia;
	int r_visao;
	int r_mov;
	int cor;
	int x, y;
	//Variação de energica, só com as migalhas

public:
	
	// CONSTRUTOR
	Formiga(char t, int x, int y);
		
	// SET'S
	void set_tipo(char t);
	void set_formiga();
	void set_posX(int x);
	void set_posY(int y);

	// GET'S
	char get_tipo() const;
	int get_posX() const;
	int get_posY() const;
	int get_energia() const;
	int get_visao() const;
	int get_move() const;
	int get_cor() const;

	// FUNCOES
	void anda();

};

#endif