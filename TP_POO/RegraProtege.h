#pragma once
#include "Regra.h"

class RegraProtege : public Regra
{
public:
	RegraProtege();
	~RegraProtege();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override {
		return new RegraProtege(*this);
	}
};


