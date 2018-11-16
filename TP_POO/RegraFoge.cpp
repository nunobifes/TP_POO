#include "RegraFoge.h"
#include "Mundo.h"

RegraFoge::RegraFoge()
{
}

RegraFoge::~RegraFoge()
{
}

bool RegraFoge::verificaCondicao(Mundo * m, Formiga * form)
{

	int id = form->get_id();
	int raio = form->get_visao();
	int x = form->get_posX();
	int y = form->get_posY();
	double energia = form->get_energia();
	double energiab = form->get_energiab();
	if (energia <= energiab || energia >= (energiab / 2)) {

		for (auto i = 0; i < m->get_comunidade().size(); i++)
		{
			Comunidade *c = m->get_comunidade().at(i);
			for (auto j = 0; j < c->get_formiga().size(); j++)
			{
				Formiga * f = c->get_formiga().at(j);
				int fx = f->get_posX();
				int fy = f->get_posY();
				if (id == f->get_id())
					break;

				if (max(abs(x - fx), abs(y - fy)) <= raio)
				{
					fini = f;
					return true;
				}

			}
		}
	}
	else
		return false;

	return false;
}

void RegraFoge::Accao(Mundo * m, Formiga * form)
{
	
	int x = form->get_posX();
	int y = form->get_posY();
	int xini = fini->get_posX();
	int yini = fini->get_posY();
	int movx;
	int movy;

	if (abs(xini - x) <= abs(yini - y) && xini >= x)
	{
		if(xini == x)
		{
			movx = rand() % form->get_move()+1;
			x = x - movx;
			movy = 0;
		}
		else {
			movx = rand() % form->get_move();
			movy = rand() % form->get_move();
			x = x - movx;
			if (yini > y)
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

		

		if( ( abs( ( x - movx ) - x ) + abs( ( y - movy ) - y ) ) > 0)
		{
			form->contr_energia(-(1 + (abs((x - movx) - x) + abs((y - movy) - y))));
			form->set_posX(x);
			form->set_posY(y);
		}
		
	}
	else if (abs(xini - x) <= abs(yini - y) && xini <= x)
	{
		if (xini == x)
		{
			movx = rand() % form->get_move() + 1;
			x = x + movx;
			movy = 0;
		}
		else {
			movx = rand() % form->get_move();
			movy = rand() % form->get_move();
			x = x + movx;
			if (yini > y)
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
	else if (abs(xini - x) >= abs(yini - y) && yini >= y)
	{
		if (yini == y)
		{
			movy = rand() % form->get_move();
			y = y - movy;
			movx = 0;
		}
		else {
			movx = rand() % form->get_move();
			movy = rand() % form->get_move();
			y = y - movy;
			if (xini > x)
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
	else if (abs(xini - x) >= abs(yini - y) && yini <= y)
	{
		if (yini == y)
		{
			movy = rand() % form->get_move();
			y = y + movy;
			movx = 0;
		}
		else {
			movx = rand() % form->get_move();
			movy = rand() % form->get_move();
			y = y + movy;
			if (xini > x)
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


	
}


