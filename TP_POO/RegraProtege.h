#pragma once
#include "Regra.h"

class RegraProtege : public Regra
{
public:
	RegraProtege();
	~RegraProtege();

	bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	void Accao(Mundo *m, Comunidade *cm, Formiga *form) const;


};


