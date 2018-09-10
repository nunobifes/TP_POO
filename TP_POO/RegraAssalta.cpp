#include "RegraAssalta.h"
#include "Mundo.h"

RegraAssalta::RegraAssalta()
{
}

RegraAssalta::~RegraAssalta()
{
}

bool RegraAssalta::verificaCondicao(Mundo * m, Formiga * form)
{
	return false;
}

void RegraAssalta::Accao(Mundo * m, Formiga * form) 
{
}

Regra * RegraAssalta::duplica() const 
{
	return new RegraAssalta(*this);
}







