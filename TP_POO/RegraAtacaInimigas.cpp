#include "RegraAtacaInimigas.h"
#include "Mundo.h"


RegraAtacaInimigas::RegraAtacaInimigas()
{
}

RegraAtacaInimigas::~RegraAtacaInimigas()
{
}

bool RegraAtacaInimigas::verificaCondicao(Mundo * m, Formiga * form)
{
	return false;
}

void RegraAtacaInimigas::Accao(Mundo * m, Formiga * form)
{
}

Regra * RegraAtacaInimigas::duplica() const
{
	return new RegraAtacaInimigas(*this);
}
