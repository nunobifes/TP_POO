#include "RegraVaiParaNinho.h"
#include "Mundo.h"

RegraVaiParaNinho::RegraVaiParaNinho()
{
}

RegraVaiParaNinho::~RegraVaiParaNinho()
{
}



bool RegraVaiParaNinho::verificaCondicao(Mundo * m, Formiga * form)
{	
	int id = form->get_id();
	int raio = form->get_visao();
	double energia = form->get_energia();
	double energiab = form->get_energiab();
	int x = form->get_posX();
	int y = form->get_posY();

	for (auto i = 0; i < m->get_comunidade().size(); i++)
	{
		Comunidade *c = m->get_comunidade().at(i);
		Ninho *n = c->get_ninho();
		
		int nx = n->getPosX();
		int ny = n->getPosY();

			if (id != c->get_id())
				break;

			if (m->get_ite()>10) {
				if (energia > energiab || energia < (energiab / 2))
				{
					if (max(abs(x - nx), abs(y - ny)) <= raio)
					{
						ni = n;
						return true;
					}
				}
				else
				{
					return false;
				}
			}else
			{
				return false;
			}
			
		
	}
	return false;
}

void RegraVaiParaNinho::Accao(Mundo * m, Formiga * form)
{
	int x = form->get_posX();
	int y = form->get_posY();
	int xn = ni->getPosX();
	int yn = ni->getPosY();
	int movx, movy;

	if (x == xn && y == yn)
		return;

	if (abs(xn - x) <= abs(yn - y) && xn >= x)
	{
		if (max(abs(x - xn), abs(y - yn)) <= form->get_move()) {
			x = xn;
			y = yn;
		}
		else {
			if (xn == x)
			{
				movx = rand() % form->get_move() + 1;
				x = x + movx;
				movy = 0;
			}
			else {
				movx = rand() % form->get_move();
				movy = rand() % form->get_move();
				x = x + movx;
				if (yn > y)
					y = y - movy;
				else
					y = y + movy;
			}

			if (x < 0)
				x = 0;

			if (x >= m->get_lim())
				x = m->get_lim() - 1;

			if (y < 0)
				y = 0;

			if (y >= m->get_lim())
				y = m->get_lim() - 1;

			if ((abs((x - movx) - x) + abs((y - movy) - y)) > 0)
			{
				form->contr_energia(-(1 + (abs((x - movx) - x) + abs((y - movy) - y))));
				form->set_posX(x);
				form->set_posY(y);
			}
		}
		if ((abs((x - xn) - x) + abs((y - yn) - y)) > 0)
		{
			form->contr_energia(-(1 + (abs((x - xn) - x) + abs((y - yn) - y))));
			form->set_posX(x);
			form->set_posY(y);
		}
	}
	else if (abs(xn - x) <= abs(yn - y) && xn <= x)
	{
		if (max(abs(x - xn), abs(y - yn)) <= form->get_move()) {
			x = xn;
			y = yn;
		}
		else {
			if (xn == x)
			{
				movx = rand() % form->get_move() + 1;
				x = x - movx;
				movy = 0;
			}
			else {
				movx = rand() % form->get_move();
				movy = rand() % form->get_move();
				x = x - movx;
				if (yn > y)
					y = y - movy;
				else
					y = y + movy;
			}

			if (x < 0)
				x = 0;

			if (x >= m->get_lim())
				x = m->get_lim() - 1;

			if (y < 0)
				y = 0;

			if (y >= m->get_lim())
				y = m->get_lim() - 1;
			
			if ((abs((x - movx) - x) + abs((y - movy) - y)) > 0)
			{
				form->contr_energia(-(1 + (abs((x - movx) - x) + abs((y - movy) - y))));
				form->set_posX(x);
				form->set_posY(y);
			}
		}
		if ((abs((x - xn) - x) + abs((y - yn) - y)) > 0)
		{
			form->contr_energia(-(1 + (abs((x - xn) - x) + abs((y - yn) - y))));
			form->set_posX(x);
			form->set_posY(y);
		}

	}
	else if (abs(xn - x) >= abs(yn - y) && yn >= y)
	{
		if (max(abs(x-xn), abs(y-yn)) <= form->get_move() ){
			x = xn;
			y = yn;
		}
		else {
			if (yn == y)
			{
				movy = rand() % form->get_move();
				y = y + movy;
				movx = 0;
			}
			else {
				movx = rand() % form->get_move();
				movy = rand() % form->get_move();
				y = y + movy;
				if (xn > x)
					x = x - movx;
				else
					x = x + movy;
			}

			if (x < 0)
				x = 0;

			if (x >= m->get_lim())
				x = m->get_lim() - 1;

			if (y < 0)
				y = 0;

			if (y >= m->get_lim())
				y = m->get_lim() - 1;
			
			if ((abs((x - movx) - x) + abs((y - movy) - y)) > 0)
			{
				form->contr_energia(-(1 + (abs((x - movx) - x) + abs((y - movy) - y))));
				form->set_posX(x);
				form->set_posY(y);
			}
		}
		if ((abs((x - xn) - x) + abs((y - yn) - y)) > 0)
		{
			form->contr_energia(-(1 + (abs((x - xn) - x) + abs((y - yn) - y))));
			form->set_posX(x);
			form->set_posY(y);
		}
	}
	else if (abs(xn - x) >= abs(yn - y) && yn <= y)
	{
		if (max(abs(x - xn), abs(y - yn)) <= form->get_move() ){
			x = xn;
			y = yn;
		}
		else {
			if (yn == y)
			{
				movy = rand() % form->get_move();
				y = y - movy;
				movx = 0;
			}
			else {
				movx = rand() % form->get_move();
				movy = rand() % form->get_move();
				y = y - movy;
				if (xn > x)
					x = x - movx;
				else
					x = x + movy;
			}

			if (x < 0)
				x = 0;

			if (x >= m->get_lim())
				x = m->get_lim() - 1;

			if (y < 0)
				y = 0;

			if (y >= m->get_lim())
				y = m->get_lim() - 1;

			if ((abs((x - movx) - x) + abs((y - movy) - y)) > 0)
			{
				form->contr_energia(-(1 + (abs((x - movx) - x) + abs((y - movy) - y))));
				form->set_posX(x);
				form->set_posY(y);
			}
		}
		if ((abs((x - xn) - x) + abs((y - yn) - y)) > 0)
		{
			form->contr_energia(-(1 + (abs((x - xn) - x) + abs((y - yn) - y))));
			form->set_posX(x);
			form->set_posY(y);
		}
	}
	return;
}

