#pragma once
#include "Regra.h"

class RegraProtegida : public Regra
{
public:
	RegraProtegida();
	~RegraProtegida();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override;
};
