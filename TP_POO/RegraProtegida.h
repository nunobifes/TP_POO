#pragma once
#include "Regra.h"

class RegraProtegida : public Regra
{
public:
	RegraProtegida();
	~RegraProtegida();

	bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	void Accao(Mundo *m, Comunidade *cm, Formiga *form) const;


};
