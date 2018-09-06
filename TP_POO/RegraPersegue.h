#pragma once
#include "Regra.h"

class RegraPersegue : public Regra
{
public:
	RegraPersegue();
	~RegraPersegue();

	bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	void Accao(Mundo *m, Comunidade *cm, Formiga *form) const;


};