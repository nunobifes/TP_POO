#include "Exploradora.h"


// CONSTRUTOR
Exploradora::Exploradora()
{
}

// DESTRUTOR
Exploradora::~Exploradora()
{
}

// SET'S

// GET'S
int Exploradora::get_r_visao() const
{
	return 10;
}
int Exploradora::get_r_mov() const
{
	return 8;
}
int Exploradora::get_e_inicial() const
{
	return 200;
}
char Exploradora::get_tipo() const
{
	return 'E';
}
int Exploradora::get_cor() const
{
	return 2;
}

// FUNCOES