#include "RegraProcuraMigalha.h"
#include "Mundo.h"

RegraProcuraMigalha::RegraProcuraMigalha()
{
}

RegraProcuraMigalha::~RegraProcuraMigalha()
{
}

bool RegraProcuraMigalha::verificaCondicao(Mundo * m, Comunidade * cm, Formiga * form)
{
	//Em falta....
	return false;
}

void RegraProcuraMigalha::Accao(Mundo * m, Comunidade * cm, Formiga * form) const
{
	int x = mig->get_posx();
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
	}
}

//Duplica....


