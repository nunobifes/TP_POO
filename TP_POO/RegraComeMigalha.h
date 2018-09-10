#include "Regra.h"
#include "Migalha.h"

class RegraComeMigalha : public Regra
{
	Migalha *miga;
public:
	RegraComeMigalha();

	~RegraComeMigalha();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override;



};
