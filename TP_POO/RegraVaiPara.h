#pragma once

#include "Regra.h"
#include "Ninho.h"

class RegraVaiPara : public Regra
{
	Comunidade *ni;

public:
	RegraVaiPara();

	~RegraVaiPara();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override {
		return new RegraVaiPara(*this);
	}

};
