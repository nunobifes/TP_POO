#include "Regra.h"
#include "Migalha.h"

class RegraProcuraMigalha : public Regra
{
	Migalha *mig = nullptr;

public:
	RegraProcuraMigalha();

	~RegraProcuraMigalha();

	virtual bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	void Accao(Mundo *m, Comunidade *cm, Formiga *form)const;

	//Duplica?

	

};
