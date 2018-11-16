#pragma once

#include "Regra.h"

class RegraAssalta : public Regra
{
	Formiga *fini;
public:
	RegraAssalta();
	~RegraAssalta();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override {
		return new RegraAssalta(*this);
	}
};