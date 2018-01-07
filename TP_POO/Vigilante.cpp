#include "Vigilante.h"


// CONSTRUTOR
Vigilante::Vigilante()
{
}

// DESTRUTOR
Vigilante::~Vigilante()
{
}

// SET'S

// GET'S
int Vigilante::get_r_visao() const
{
	return 7;
}
int Vigilante::get_r_mov() const
{
	return 5;
}
int Vigilante::get_e_inicial() const
{
	return 150;
}
char Vigilante::get_tipo() const
{
	return 'V';
}
int Vigilante::get_cor() const
{
	return 8;
}

// FUNCOES