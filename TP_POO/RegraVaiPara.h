#pragma once

#include "Regra.h"
#include "Ninho.h"

class RegraVaiPara : public Regra
{
	Ninho *ni;

public:
	RegraVaiPara();

	~RegraVaiPara();

	bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	virtual void Accao(Mundo *m, Comunidade *cm, Formiga *form)const;

	//Duplica?



};
