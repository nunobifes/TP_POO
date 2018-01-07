#include "Assaltante.h"


// CONSTRUTOR
Assaltante::Assaltante()
{
}

// DESTRUTOR
Assaltante::~Assaltante()
{
}

// SET'S

// GET'S
int Assaltante::get_r_visao() const
{
	return 8;
}
int Assaltante::get_r_mov() const
{
	return 4;
}
int Assaltante::get_e_inicial() const
{
	return 80;
}
char Assaltante::get_tipo() const
{
	return 'A';
}
int Assaltante::get_cor() const
{
	return 4;
}

// FUNCOES