#include "Regra.h"



Regra::Regra(const Regra & obj)
{
	*this = obj;
}

bool Regra::get_continua() const
{
	return continua;
}

Regra::Regra()
{

}

Regra::~Regra()
{

}

/*Regra * Regra::duplica() const
{
	return new Regra(*this);
}*/

