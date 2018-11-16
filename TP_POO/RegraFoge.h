
#include "Regra.h"
#include <vector>


class RegraFoge : public Regra 
{
	Formiga *fini;  //Inimigo

public:
	RegraFoge();
	~RegraFoge();

	virtual bool verificaCondicao(Mundo *m, Formiga *form);
	virtual void Accao(Mundo *m, Formiga *form);

	virtual Regra* duplica() const override {
		return new RegraFoge(*this);
	}
};

