#pragma once
#include "Regra.h"

class RegraPersegue : public Regra
{
public:
	RegraPersegue();
	~RegraPersegue();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override;
};