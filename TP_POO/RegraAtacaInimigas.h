#pragma once
#include "Regra.h"

class RegraAtacaInimigas : public Regra
{
public:
	RegraAtacaInimigas();
	~RegraAtacaInimigas();

	bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	void Accao(Mundo *m, Comunidade *cm, Formiga *form) const;


};
