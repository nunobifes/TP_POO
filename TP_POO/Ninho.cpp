//Um ninho serve essencialmente para criar 
//novas formigas e também como refúgio de algumas das formigas existentes na sua comunidade.

#include "Formiga.h"
#include "Ninho.h"
#include "Mundo.h"

//char Ninho::ident = 'N';

Ninho::Ninho(int id, int e, int x, int y, bool g, Comunidade* c, Mundo* m)
:id(id),energia(e), x(x), y(y), guerra(g), cn(c), mn(m)
{

	e_base = energia;
	
	//cerr << "id: " << id << " energia: " << energia << " posx: " << this->x << " posy: " << this->y << endl;
}

Ninho::Ninho(Ninho& n)
{
	id = n.id;
	energia = n.energia;
	x = n.x;
	y = n.y;
	guerra = n.guerra;
	cn = n.cn;
	mn = n.mn;
	e_base = n.e_base;
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

void Ninho::setGuerra(bool g)
{
	this->guerra = g;
}

void Ninho::setPosY(int y) {
	this->y = y;
}

int Ninho::get_id() const
{
	return id;
}

bool Ninho::get_guerra() const
{
	return guerra;
}

int Ninho::get_energia_b() const
{
	return e_base;
}


void Ninho::contr_energia(int ener)
{
	this->energia += ener;
}




string Ninho::lista_info() const
{
	string info;
	ostringstream oss;
	oss << "Energia: " << this->energia << " PosX: " << this->x << " PosY: " << this->y << " Guerra: " << this->guerra << endl;
	info = oss.str();

	return info;
}




Ninho::~Ninho() {

	delete cn;
	delete mn;

}