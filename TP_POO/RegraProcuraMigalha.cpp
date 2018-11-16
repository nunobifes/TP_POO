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

	int raio = form->get_visao();
	int x = form->get_posX();
	mig = nullptr;
	int y = form->get_posY();
	double energia = form->get_energia();
	double energiab = form->get_energiab();

	if (energia <= energiab || energia >=(energiab / 2)) {

		for (auto i = 0; i < m->get_migalha().size(); i++)
		{
			Migalha *mg = m->get_migalha().at(i);
			int mx = mg->get_posx();
			int my = mg->get_posy();

			if (max(abs(x - mx), abs(y - my)) <= raio)
			{
				if (mig == nullptr || mig->get_energia() < mg->get_energia())
					mig = mg;
			}
		}
		if (mig == nullptr)
			return false;
		else
			return true;
	}
	else
		return false;
}

void RegraProcuraMigalha::Accao(Mundo * m, Formiga * form)
{
	int x = form->get_posX();
	int y = form->get_posY();
	int xini = mig->get_posx();
	int yini = mig->get_posy();
	int movx;
	int movy;

	if (abs(xini - x) <= abs(yini - y) && xini >= x)
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
	else if (abs(xini - x) <= abs(yini - y) && xini <= x)
	{
		if (xini == x)
		{
			movx = rand() % form->get_move() + 1;
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
	else if (abs(xini - x) >= abs(yini - y) && yini <= y)
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
}





