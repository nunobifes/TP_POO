#include "RegraProtegida.h"

RegraProtegida::RegraProtegida()
{
}

RegraProtegida::~RegraProtegida()
{
}

Regra * RegraProtegida::duplica() const
{
	return new RegraProtegida(*this);
}

bool RegraProtegida::verificaCondicao(Mundo * m, Formiga * form)
{
	return false;
}

void RegraProtegida::Accao(Mundo * m, Formiga * form)
{
}
