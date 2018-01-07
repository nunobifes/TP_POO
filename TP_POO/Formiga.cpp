#include "Formiga.h"

// CONSTRUTOR
Formiga::Formiga(char t, int x, int y)
	:tipo(t), x(x), y(y)
{
	set_formiga();
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
void Formiga::set_formiga() {

	if(tipo != 'C' && tipo != 'V' && tipo != 'A' && tipo != 'E')
	{
		int f_rand = rand() % 4; // cuidadora - 0, vigilante - 1, assaltante - 2, exploradora - 3
		if(f_rand == 0)
		{
			Cuidadora* c = new Cuidadora();
			this->r_visao = c->get_r_visao();
			this->r_mov = c->get_r_mov();
			this->energia = c->get_e_inicial();
			this->cor = c->get_cor();
			
		} else if(f_rand == 1)
		{
			Vigilante* v = new Vigilante();
			this->r_visao = v->get_r_visao();
			this->r_mov = v->get_r_mov();
			this->energia = v->get_e_inicial();
			this->cor = v->get_cor();

		} else if (f_rand == 2)
		{
			Assaltante* a = new Assaltante();
			this->r_visao = a->get_r_visao();
			this->r_mov = a->get_r_mov();
			this->energia = a->get_e_inicial();
			this->cor = a->get_cor();

		} else if (f_rand == 3)
		{
			Exploradora* e = new Exploradora();
			this->r_visao = e->get_r_visao();
			this->r_mov = e->get_r_mov();
			this->energia = e->get_e_inicial();
			this->cor = e->get_cor();

		}
	} else
	{
		if (tipo == 'C')
		{
			Cuidadora* c = new Cuidadora();
			this->r_visao = c->get_r_visao();
			this->r_mov = c->get_r_mov();
			this->energia = c->get_e_inicial();
			this->cor = c->get_cor();

		}
		else if (tipo == 'V')
		{
			Vigilante* v = new Vigilante();
			this->r_visao = v->get_r_visao();
			this->r_mov = v->get_r_mov();
			this->energia = v->get_e_inicial();
			this->cor = v->get_cor();

		}
		else if (tipo == 'A')
		{
			Assaltante* a = new Assaltante();
			this->r_visao = a->get_r_visao();
			this->r_mov = a->get_r_mov();
			this->energia = a->get_e_inicial();
			this->cor = a->get_cor();

		}
		else if (tipo == 'E')
		{
			Exploradora* e = new Exploradora();
			this->r_visao = e->get_r_visao();
			this->r_mov = e->get_r_mov();
			this->energia = e->get_e_inicial();
			this->cor = e->get_cor();

		}
	}



	
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
int Formiga::get_cor() const
{
	return cor;
}

// FUNCOES
void Formiga::anda()
{
	
	int x = this->x; 
	int y = this->y;
	




	this->x = x;
	this->y = y;


}