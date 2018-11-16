#include "Regra.h"
#include "Migalha.h"

class RegraProcuraMigalha : public Regra
{
	Migalha *mig;

public:
	RegraProcuraMigalha();

	~RegraProcuraMigalha();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override {
		return new RegraProcuraMigalha(*this);
	}

	

};
