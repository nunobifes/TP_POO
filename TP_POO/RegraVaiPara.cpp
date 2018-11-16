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
	int id = form->get_id();

	for(auto i = 0; i < m->get_comunidade().size(); i++)
	{
		Comunidade* c = m->get_comunidade().at(i);

		if (c->get_id() == id) {
			if (c->get_guerra() != nullptr) {
				ni = c->get_guerra();
				return true;
			}
			else
				return false;
		}
	}
	return false;
}

void RegraVaiPara::Accao(Mundo * m, Formiga * form)
{
	int x = form->get_posX();
	int y = form->get_posY();
	int xn = ni->get_ninho()->getPosX();
	int yn = ni->get_ninho()->getPosY();
	int mov, movy, movx;

	if(max(abs(x - xn), abs(y - yn)) <= form->get_move())
	{
		mov = rand() % 1;
		if (mov = 0)
			x = xn + 1;
		else
			x = xn - 1;

		mov = rand() % 1;
		if (mov = 0)
			y = yn + 1;
		else
			y = yn - 1;

		if ((abs((x - xn) - x) + abs((y - yn) - y)) > 0)
		{
			form->contr_energia(-(1 + (abs((x - xn) - x) + abs((y - yn) - y))));
			form->set_posX(x);
			form->set_posY(y);
		}
	}
	else
	{
		if (abs(xn - x) <= abs(yn - y) && xn >= x)
		{
			
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
		else if (abs(xn - x) <= abs(yn - y) && xn <= x)
		{
			
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
		else if (abs(xn - x) >= abs(yn - y) && yn >= y)
		{
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
		else if (abs(xn - x) >= abs(yn - y) && yn <= y)
		{

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
	}

}
