#pragma once
#include "Regra.h"

class RegraPersegue : public Regra
{
	Formiga *fini;
public:
	RegraPersegue();
	~RegraPersegue();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override {
		return new RegraPersegue(*this);
	}
};