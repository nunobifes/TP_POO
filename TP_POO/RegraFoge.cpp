#include "RegraFoge.h"
#include "Mundo.h"

RegraFoge::RegraFoge()
{
}

RegraFoge::~RegraFoge()
{
}

bool RegraFoge::verificaCondicao(Mundo * m, Formiga * form)
{
	// Em falta....
	return false;
			
}

void RegraFoge::Accao(Mundo * m, Formiga * form)
{
	


}

Regra * RegraFoge::duplica() const
{
	return new RegraFoge(*this);
}


