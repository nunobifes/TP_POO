#include "Migalha.h"



Migalha::Migalha(int e, int x, int y)
	:energia(e), x(x), y(y) { }

void Migalha::set_energia(int e)
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

int Migalha::get_energia() const
{
	return energia;
}

int Migalha::get_posx() const
{
	return x;
}

int Migalha::get_posy() const
{
	return y;
}
