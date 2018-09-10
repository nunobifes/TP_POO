#include "RegraPersegue.h"
#include "Mundo.h"

RegraPersegue::RegraPersegue()
{
}

RegraPersegue::~RegraPersegue()
{
}

bool RegraPersegue::verificaCondicao(Mundo * m, Formiga * form)
{
	return false;
}

void RegraPersegue::Accao(Mundo * m, Formiga * form)
{
}

Regra * RegraPersegue::duplica() const
{
	return new RegraPersegue(*this);
}
