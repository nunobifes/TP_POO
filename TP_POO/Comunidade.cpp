#include "Comunidade.h"
#include "Formiga_Tipo.h"

int Comunidade::conta = 1;

Comunidade::Comunidade(Mundo* m, int cor)
	:cor(cor)
{
	id = conta++;
	ni = new Ninho(id, m->get_energia_ninho(), m->get_posx_ninho(), m->get_posy_ninho(), this, m);
	
}


int Comunidade::get_cor() const
{
	return cor;
}

int Comunidade::get_id() const
{
	return id;
}

void Comunidade::add_formiga(int lim, char t, int x, int y)
{
	if(t != 0)
	{
		Formiga* fo;
		if (t == 'C') {
			fo = new Cuidadora(x, y);
		}
		else if (t == 'V') {
			fo = new Vigilante(x, y);
		}
		else if (t == 'A') {
			fo = new Assaltante(x, y);
		}
		else if (t == 'E') {
			fo = new Exploradora(x, y);
		}
		

		if(x < 0 && y < 0)
		{
			int xr = (rand() % lim) + 59;
			int yr = (rand() % lim) + 18;
			fo->set_posX(xr);
			fo->set_posY(yr);
		}
		// corrigir
		form.push_back(fo);



	}
	else
	{
		int randT = rand() % 4;
		Formiga * fo;
		switch(randT)
		{
		case 0:
			fo = new Cuidadora(ni->getPosX(), ni->getPosY());
			form.push_back(fo);
			break;
		case 1:
			fo = new Vigilante(ni->getPosX(), ni->getPosY());
			form.push_back(fo);
			break;
		case 2:
			fo = new Assaltante(ni->getPosX(), ni->getPosY());
			form.push_back(fo);
			break;
		case 3:
			fo = new Exploradora(ni->getPosX(), ni->getPosY());
			form.push_back(fo);
			break;
		default:
			break;

		}

	}
	
}
