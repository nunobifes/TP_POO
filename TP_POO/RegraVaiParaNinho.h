#pragma once

#include "Regra.h"
#include "Ninho.h"

class RegraVaiParaNinho : public Regra
{
	Ninho *ni;

public:
	RegraVaiParaNinho();

	~RegraVaiParaNinho();

	bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	virtual void Accao(Mundo *m, Comunidade *cm, Formiga *form)const;

	//Duplica?



};