#ifndef __VIGILANTE__
#define __VIGILANTE__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <windows.h>
#include <vector>

using namespace std;

class Vigilante
{
	
public:
	// CONSTRUTOR
	Vigilante();

	// DESTRUTOR
	~Vigilante();

	// SET'S
	
	// GET'S
	int get_r_visao() const;
	int get_r_mov() const;
	int get_e_inicial() const;
	char get_tipo() const;
	int get_cor() const;

	// FUNCOES
};

#endif