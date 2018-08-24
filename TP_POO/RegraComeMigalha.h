#include "Regra.h"
#include "Migalha.h"

class RegraComeMigalha : public Regra
{
public:
	RegraComeMigalha();

	~RegraComeMigalha();

	virtual bool verificaCondicao(Mundo *m, Comunidade *cm, Formiga *form);
	void Accao(Mundo *m, Comunidade *cm, Formiga *form)const;

	//Duplica?



};
