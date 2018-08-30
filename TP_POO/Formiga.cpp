#include "Formiga.h"
#include "Mundo.h"

// CONSTRUTOR
Formiga::Formiga(int e, int rv, int rm, char t, int x, int y, int lim)
	:energia(e), r_visao(rv), r_mov(rm), tipo(t), x(x), y(y), lim_m(lim)
{
	//set_formiga();
	e_base = energia;
}

Formiga::Formiga(Formiga& f)
{
	energia = f.energia;
	r_visao = f.r_visao;
	r_mov = f.r_mov;
	tipo = f.tipo;
	x = f.x;
	y = f.y;
	lim_m = f.lim_m;
	e_base = f.e_base;
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
int Formiga::get_energiab() const
{
	return  e_base;
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
	
	int form;
	int mov;
	form = rand() % 4;
	switch(form)
	{
	case 0:
		mov = rand() % r_mov + 1;
		x = x + mov;
		if (x < 0)
			x = 0;
		if (x >= lim_m)
			x = lim_m-1;
		contr_energia(-(1 + mov));
		break;
	case 1:
		mov = rand() % r_mov + 1;
		x = x - mov;
		if (x < 0)
			x = 0;
		if (x >= lim_m)
			x = lim_m - 1;
		contr_energia(-(1 + mov));
		break;
	case 2:
		mov = rand() % r_mov + 1;
		y = y + mov;
		if (y < 0)
			y = 0;
		if (y >= lim_m)
			y = lim_m - 1;
		contr_energia(-(1 + mov));
		break;
	case 3:
		mov = rand() % r_mov + 1;
		y = y - mov;
		if (y < 0)
			y = 0;
		if (y >= lim_m)
			y = lim_m - 1;
		contr_energia(-(1 + mov));
		break;
	default:
		break;
	}
	this->x = x;
	this->y = y;
}

void Formiga::contr_energia(int ener)
{
	this->energia += ener;
}

void Formiga::comeu_migalha(Mundo *m)
{

	

	
	
}

string Formiga::lista_info() const
{
	string info;
	ostringstream oss;
	oss << "Tipo: " << this->tipo << " Energia: " << this->energia << " PosX: " << this->x << " PosY: " << this->y << endl;
	info = oss.str();

	return info;
}
