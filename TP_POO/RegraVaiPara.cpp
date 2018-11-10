#include "RegraVaiPara.h"
#include "Mundo.h"

RegraVaiPara::RegraVaiPara()
{
}

RegraVaiPara::~RegraVaiPara()
{
}

bool RegraVaiPara::verificaCondicao(Mundo * m, Formiga * form)
{
	int raio_visao = form->get_visao();

	int vxs = form->get_posX() + raio_visao;
	int vxi = form->get_posX() - raio_visao;

	int vys = form->get_posY() + raio_visao;
	int vyi = form->get_posY() - raio_visao;

	for (auto i = 1; i < m->get_comunidade().size(); i++)
	{
		ni = m->get_comunidade().at(i)->get_ninho();

		if (ni->getPosX() != vxs + i && ni->getPosY() != vys + i)
			if (ni->getPosX() != vxi - i && ni->getPosY() != vyi - i)
				if (ni->getPosX() != vxs + i && ni->getPosY() != vyi - i)
					if (ni->getPosX() != vxi - i && ni->getPosY() != vys + i)
						return false;

	}
	return true;
}

void RegraVaiPara::Accao(Mundo * m, Formiga * form)
{

}

Regra * RegraVaiPara::duplica() const
{
	return new RegraVaiPara(*this);
}
