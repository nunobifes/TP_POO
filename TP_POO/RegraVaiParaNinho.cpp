#include "RegraVaiParaNinho.h"
#include "Mundo.h"

RegraVaiParaNinho::RegraVaiParaNinho()
{
}

RegraVaiParaNinho::~RegraVaiParaNinho()
{
}

bool RegraVaiParaNinho::verificaCondicao(Mundo * m, Comunidade * cm, Formiga * form)
{

	return false;
}

void RegraVaiParaNinho::Accao(Mundo * m, Comunidade * cm, Formiga * form) const
{
	int x = ni->getPosX();
	int y = ni->getPosY();

	if (ni->getPosX() > form->get_posX())
		form->set_posX(form->get_posX() + rand() % form->get_move() + 1);

	else {
		if (ni->getPosX() < form->get_posX())
			form->set_posX(form->get_posX() - rand() % form->get_move() + 1);
		
		else {
			if (ni->getPosY() > form->get_posY())
				form->set_posY(form->get_posY() + rand() % form->get_move() + 1);

			else {
				if (ni->getPosY() < form->get_posY())
					form->set_posY(form->get_posY() - rand() % form->get_move() + 1);
			}
		}
	}

}

