//Um ninho serve essencialmente para criar 
//novas formigas e também como refúgio de algumas das formigas existentes na sua comunidade.

#include "Formiga.h"
#include "Ninho.h"
#include "Mundo.h"

//char Ninho::ident = 'N';

Ninho::Ninho(int id, int e, int x, int y, Comunidade* c, Mundo* m)
:id(id),energia(e), x(x), y(y), cn(c), mn(m)
{
	
	cerr << "id: " << id << " energia: " << energia << " posx: " << this->x << " posy: " << this->y << endl;
}

void Ninho::set_comunid(Comunidade* c)
{
	this->cn = c;
}

void Ninho::set_mundo(Mundo* m)
{
	this->mn = m;
}

void Ninho::setEnergia(int e) {
	this->energia = e;
}


void Ninho::setPosX(int x) {
	this->x = x;
}

void Ninho::setPosY(int y) {
	this->y = y;
}

int Ninho::get_id() const
{
	return id;
}




Ninho::~Ninho() {

}