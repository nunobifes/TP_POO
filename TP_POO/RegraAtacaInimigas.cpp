#include "RegraAtacaInimigas.h"
#include "Mundo.h"


RegraAtacaInimigas::RegraAtacaInimigas()
{
}

RegraAtacaInimigas::~RegraAtacaInimigas()
{
}

bool RegraAtacaInimigas::verificaCondicao(Mundo * m, Formiga * form)
{
	int id = form->get_id();
	int raio = form->get_move();
	int x = form->get_posX();
	int y = form->get_posY();
	fini = nullptr;

	for (auto i = 0; i < m->get_comunidade().size(); i++)
	{
		Comunidade* c = m->get_comunidade().at(i);

		if (c->get_id() == id) {
			if (c->get_guerra() != nullptr) {
				
				for(auto j = 0; j < c->get_formiga().size(); j++)
				{
					Formiga* f = c->get_formiga().at(i);
					int fx = f->get_posX();
					int fy = f->get_posY();

					if (c->get_guerra()->get_id() == f->get_id())
					{
						if (max(abs(x - fx), abs(y - fy)) <= raio)
						{
							if (fini == nullptr || fini->get_energia() < f->get_energia())
								fini = f;
						}
					}
				}
			}
			else
				return false;
		}
		if (fini != nullptr)
			return true;
	}
	return false;
}

void RegraAtacaInimigas::Accao(Mundo * m, Formiga * form)
{

	double energia = form->get_energia();
	double energiab = form->get_energiab();
	double fenergia = fini->get_energia();
	double fenergiab = fini->get_energiab();
	int x = form->get_posX();
	int y = form->get_posY();
	int fx = fini->get_posX();
	int fy = fini->get_posY();
	int orix = x, oriy = y;

	if (fx > x)
		x = fx - 1;
	else if (fx < x)
		x = fx + 1;

	if (fy > y)
		y = fy - 1;
	else if (fy < y)
		y = fy + 1;

	if ((abs(orix - x) + abs(oriy - y)) > 0)
	{
		form->contr_energia(-(1 + (abs(orix - x) + abs(oriy - y))));
		form->set_posX(x);
		form->set_posY(y);
	}
	if (fenergia < (fenergiab*0.5))
	{
		form->set_energia(energia + fenergia);
		fini->set_energia(0);
	}
	else {
		form->set_energia(energia + (fenergia*0.5));
		fini->set_energia(fenergia - (fenergia*0.5));
	}

}

