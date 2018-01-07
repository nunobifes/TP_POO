#include "Cuidadora.h"


// CONSTRUTOR
Cuidadora::Cuidadora()
{
}

// DESTRUTOR
Cuidadora::~Cuidadora()
{
}

// SET'S

// GET'S
int Cuidadora::get_r_visao() const
{
	return 5;
}
int Cuidadora::get_r_mov() const
{
	return 3;
}
int Cuidadora::get_e_inicial() const
{
	return 100;
}
char Cuidadora::get_tipo() const
{
	return 'C';
}
int Cuidadora::get_cor() const
{
	return 3;
}

// FUNCOES