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
protected:
	bool continua;
public:
	//Regra(const Regra & obj); //Construtor por c�pia -> no relatorio explicar o porqu� de ser usado aqui....
	virtual bool get_continua() const;

	Regra();

	~Regra();

	virtual bool verificaCondicao(Mundo *m, Formiga *form)=0;
	virtual void Accao(Mundo *m, Formiga *form)=0;

	virtual Regra* duplica() const = 0;

};

#endif