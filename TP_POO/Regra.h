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
	Regra(const Regra & obj); //Construtor por cópia -> no relatorio explicar o porquê de ser usado aqui....

	Regra();

	~Regra();

	virtual bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form) = 0;
	virtual void Accao(Mundo *m, Comunidade *cm, Formiga *form) = 0;

	//Duplica?

	// No enuciado da especial vamos precisar de uma nova caracteristica, será para saber se o estado é contínuo ou não 
	// Está só associado às 3 novas regras
};

#endif