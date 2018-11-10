
#include "Regra.h"


class RegraFoge : public Regra 
{
	//Formiga *enemy;  //Inimigo

public:
	RegraFoge();
	~RegraFoge();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override;
};

