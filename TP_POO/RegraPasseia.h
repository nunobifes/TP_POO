#pragma once
#include "Regra.h"

class RegraPasseia : public Regra
{
public:
	RegraPasseia();
	~RegraPasseia();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override;
};