#pragma once
#include "Regra.h"

class RegraPasseia : public Regra
{
public:
	RegraPasseia();
	~RegraPasseia();

	bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	void Accao(Mundo *m, Comunidade *cm, Formiga *form) const;

	
};