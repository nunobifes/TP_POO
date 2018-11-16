#include "RegraPasseia.h"
#include "Mundo.h"

RegraPasseia::RegraPasseia()
{
	continua = false;
}

RegraPasseia::~RegraPasseia()
{
}

bool RegraPasseia::verificaCondicao(Mundo * m, Formiga * form)
{

	return true;
}

void RegraPasseia::Accao(Mundo * m, Formiga * form)
{


	int x = form->get_posX();
	int y = form->get_posY();

	int forms;
	int movx;
	int movy;
	forms = rand() % 4;
	switch (forms)
	{
		case 0:
			movx = rand() % form->get_move();
			movy = rand() % form->get_move();
			x = x + movx;
			y = y + movy;
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
			break;
		case 1:
			movx = rand() % form->get_move();
			movy = rand() % form->get_move();
			x = x + movx;
			y = y - movy;
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
			break;
		case 2:
			movx = rand() % form->get_move();
			movy = rand() % form->get_move();
			x = x - movx;
			y = y + movy;
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
		case 3:
			movx = rand() % form->get_move();
			movy = rand() % form->get_move();
			x = x - movx;
			y = y - movy;
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
			break;

		default:
			break;

	}


}
