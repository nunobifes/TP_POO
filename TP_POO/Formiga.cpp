#include "Formiga.h"

// CONSTRUTOR
Formiga::Formiga(int e, int rv, int rm, char t, int x, int y)
	:energia(e), r_visao(rv), r_mov(rm), tipo(t), x(x), y(y)
{
	//set_formiga();
}


// SET'S
void Formiga::set_tipo(char t)
{
	this->tipo = t;
}
void Formiga::set_posX(int x) {
	this->x = x;
}
void Formiga::set_posY(int y) {
	this->y = y;
}


// GET'S
char Formiga::get_tipo() const
{
	return tipo;
}
int Formiga::get_posX() const
{
	return x;
}
int Formiga::get_posY() const
{
	return y;
}
int Formiga::get_energia() const
{
	return  energia;
}
int Formiga::get_visao() const
{
	return r_visao;
}
int Formiga::get_move() const
{
	return r_mov;
}

// FUNCOES
void Formiga::anda()
{
	
	int x = this->x; 
	int y = this->y;
	




	this->x = x;
	this->y = y;


}