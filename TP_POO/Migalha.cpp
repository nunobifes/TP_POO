#include "Migalha.h"



Migalha::Migalha(double e, int x, int y)
	:energia(e), x(x), y(y)
{
	energ_b = energia;
}

Migalha::Migalha(Migalha& mig)
{
	energia = mig.energia;
	x = mig.x;
	y = mig.y;


}

void Migalha::set_energia(double e)
{
	this->energia = e;
}

void Migalha::set_posx(int x)
{
	this->x = x;
}

void Migalha::set_posy(int y)
{
	this->y = y;
}

double Migalha::get_energia() const
{
	return energia;
}
double Migalha::get_energiaB() const
{
	return energ_b;
}

int Migalha::get_posx() const
{
	return x;
}

int Migalha::get_posy() const
{
	return y;
}

string Migalha::lista_info() const
{
	string info;
	ostringstream oss;
	oss << "Energia: " << this->energia << " PosX: " << this->x << " PosY: " << this->y << endl;
	info = oss.str();

	return info;
}
