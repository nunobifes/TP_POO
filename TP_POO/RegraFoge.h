
#include "Regra.h"


class RegraFoge : public Regra 
{
	//Formiga *enemy;  //Inimigo

public:
	RegraFoge();
	~RegraFoge();

	bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	void Accao(Mundo *m, Comunidade *cm, Formiga *form) const;

	//Duplica?
};

