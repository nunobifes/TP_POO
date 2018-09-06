#pragma once

#include "Regra.h"

class RegraAssalta : public Regra
{
public:
	RegraAssalta();
	~RegraAssalta();

	bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	void Accao(Mundo *m, Comunidade *cm, Formiga *form) const;


};