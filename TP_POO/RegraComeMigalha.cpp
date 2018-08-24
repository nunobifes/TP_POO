#include "RegraComeMigalha.h"
#include "Mundo.h"

RegraComeMigalha::RegraComeMigalha()
{
}

RegraComeMigalha::~RegraComeMigalha()
{
}

bool RegraComeMigalha::verificaCondicao(Mundo * m, Comunidade * cm, Formiga * form)
{
	Migalha *miga;
	int raio_visao = form->get_visao();

	int vxs = form->get_posX() + raio_visao;
	int vys = form->get_posY() + raio_visao;

	int vxi = form->get_posX() - raio_visao;
	int vyi = form->get_posY() - raio_visao;

	for (int i = 0; i < raio_visao; i++) 
	{
		Migalha * mig = m->get_migalha().at(i);

		if (mig->get_posx() != vxs + i && mig->get_posy() != vys + i)
			if (mig->get_posx() != vxi - i && mig->get_posy() != vyi - i)
				if (mig->get_posx() != vxs + i && mig->get_posy() != vyi - i)
					if (mig->get_posx() != vxi - i && mig->get_posy() != vys + i)
						return false;
		miga = mig;
	}

	int posXfor = form->get_posX();
	int posYfor = form->get_posY();

	int posXmig = miga->get_posx();
	int posYmig = miga->get_posy();

	if (posXfor == posXmig && posYfor == posYmig)
		return true;
	else {
		if (posXfor == posXmig && (posYfor == posYmig - 1 || posYfor == posYmig + 1))
			return true;
		else {
			if (posYfor == posYmig && (posXfor == posXmig - 1 || posXfor == posXmig + 1))
				return true;
		}
	}

	return false;
}

void RegraComeMigalha::Accao(Mundo * m, Comunidade * cm, Formiga * form) const
{


	for (auto i = 0; i < m->get_migalha().size(); i++) {
		Migalha* mig = m->get_migalha().at(i);
		int energ = mig->get_energia();
		form->set_energia(form->get_energia() + m->get_m_per_inicial() * energ);
		mig->set_energia(mig->get_energia() - m->get_m_per_inicial() * energ);

		if (mig->get_energia() < 1)
			delete mig;

	}
	
	
}