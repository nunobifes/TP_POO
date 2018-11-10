#include "RegraVaiParaNinho.h"
#include "Mundo.h"

RegraVaiParaNinho::RegraVaiParaNinho()
{
}

RegraVaiParaNinho::~RegraVaiParaNinho()
{
}

Regra * RegraVaiParaNinho::duplica() const
{
	return new RegraVaiParaNinho(*this);
}

bool RegraVaiParaNinho::verificaCondicao(Mundo * m, Formiga * form)
{	
	int raio_visao = form->get_visao();

	int vxs = form->get_posX() + raio_visao;
	int vxi = form->get_posX() - raio_visao;

	int vys = form->get_posY() + raio_visao;
	int vyi = form->get_posY() - raio_visao;

	for(auto i = 1; i < m->get_comunidade().size(); i++)
	{
		if(form->get_id() == m->get_comunidade().at(i)->get_id())
		{
			if (ni->getPosX() != vxs + i && ni->getPosY() != vys + i)
				if (ni->getPosX() != vxi - i && ni->getPosY() != vyi - i)
					if (ni->getPosX() != vxs + i && ni->getPosY() != vyi - i)
						if (ni->getPosX() != vxi - i && ni->getPosY() != vys + i)
							return false;
		}

	}

	if (form->get_energia() > form->get_energiab() || form->get_energia() < (form->get_energiab() / 2))
		return true;
	else
		return false;
}

void RegraVaiParaNinho::Accao(Mundo * m, Formiga * form)
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

