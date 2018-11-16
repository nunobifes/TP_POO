#pragma once
#include "Regra.h"

class RegraAtacaInimigas : public Regra
{
	Formiga *fini;
public:
	RegraAtacaInimigas();
	~RegraAtacaInimigas();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override
	{
		return new RegraAtacaInimigas(*this);
	}
};
