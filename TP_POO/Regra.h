#ifndef __REGRA__
#define __REGRA__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>


class Mundo;
class Comunidade;
class Formiga;

class Regra
{

public:
	Regra(const Regra & obj); //Construtor por c�pia -> no relatorio explicar o porqu� de ser usado aqui....

	Regra();

	~Regra();

	virtual bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form) = 0;
	virtual void Accao(Mundo *m, Comunidade *cm, Formiga *form) = 0;

	//Duplica?

	// No enuciado da especial vamos precisar de uma nova caracteristica, ser� para saber se o estado � cont�nuo ou n�o 
	// Est� s� associado �s 3 novas regras
};

#endif