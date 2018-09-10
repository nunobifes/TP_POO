#pragma once

#include "Regra.h"

class RegraAssalta : public Regra
{
public:
	RegraAssalta();
	~RegraAssalta();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override;
};