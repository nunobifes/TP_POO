#pragma once

#include "Regra.h"
#include "Ninho.h"

class RegraVaiParaNinho : public Regra
{
	Ninho *ni;

public:
	RegraVaiParaNinho();

	~RegraVaiParaNinho();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override {
		return new RegraVaiParaNinho(*this);
	}

};