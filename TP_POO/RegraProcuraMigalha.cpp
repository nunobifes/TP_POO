#include "RegraProcuraMigalha.h"
#include "Mundo.h"

RegraProcuraMigalha::RegraProcuraMigalha()
{
}

RegraProcuraMigalha::~RegraProcuraMigalha()
{
}

bool RegraProcuraMigalha::verificaCondicao(Mundo * m, Formiga * form)
{
	//Migalha *miga;
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

	}
	return true;
}

void RegraProcuraMigalha::Accao(Mundo * m, Formiga * form)
{
	/*int x = mig->get_posx();
	int y = mig->get_posy();

	if (mig->get_posx() > form->get_posX())
		form->set_posX(form->get_posX() + rand() % form->get_move() + 1);

	else 
	{
		if (mig->get_posx() < form->get_posX())
			form->set_posX(form->get_posX() - rand() % form->get_move() + 1);

		else
		{
			if (mig->get_posy() > form->get_posY())
				form->set_posY(form->get_posY() + rand() % form->get_move() + 1);

			else
			{
				if (mig->get_posy() < form->get_posY())
					form->set_posY(form->get_posY() - rand() % form->get_move() + 1);
			}

		}
	}*/
}

Regra * RegraProcuraMigalha::duplica() const
{
	return new RegraProcuraMigalha(*this);
}




