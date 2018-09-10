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
	int mov;
	forms = rand() % 4;
	switch (forms)
	{
		case 0:
			mov = rand() % form->get_move() + 1;
			x = x + mov;
			if (x < 0)
				x = 0;
			if (x >= m->get_lim())
				x = m->get_lim() - 1;
			form->contr_energia(-(1 + mov));
			break;
		case 1:
			mov = rand() % form->get_move() + 1;
			x = x - mov;
			if (x < 0)
				x = 0;
			if (x >= m->get_lim())
				x = m->get_lim() - 1;
			form->contr_energia(-(1 + mov));
			break;
		case 2:
			mov = rand() % form->get_move() + 1;
			y = y + mov;
			if (y < 0)
				y = 0;
			if (y >= m->get_lim())
				y = m->get_lim() - 1;
			form->contr_energia(-(1 + mov));
			break;
		case 3:
			mov = rand() % form->get_move() + 1;
			y = y - mov;
			if (y < 0)
				y = 0;
			if (y >= m->get_lim())
				y = m->get_lim() - 1;
			form->contr_energia(-(1 + mov));
			break;
		default:
			break;

	}

	form->set_posX(x);
	form->set_posY(y);

	/*int x = this->x;
	int y = this->y;

	int form;
	int mov;
	form = rand() % 4;
	switch (form)
	{
	case 0:
		mov = rand() % r_mov + 1;
		x = x + mov;
		if (x < 0)
			x = 0;
		if (x >= lim_m)
			x = lim_m - 1;
		contr_energia(-(1 + mov));
		break;
	case 1:
		mov = rand() % r_mov + 1;
		x = x - mov;
		if (x < 0)
			x = 0;
		if (x >= lim_m)
			x = lim_m - 1;
		contr_energia(-(1 + mov));
		break;
	case 2:
		mov = rand() % r_mov + 1;
		y = y + mov;
		if (y < 0)
			y = 0;
		if (y >= lim_m)
			y = lim_m - 1;
		contr_energia(-(1 + mov));
		break;
	case 3:
		mov = rand() % r_mov + 1;
		y = y - mov;
		if (y < 0)
			y = 0;
		if (y >= lim_m)
			y = lim_m - 1;
		contr_energia(-(1 + mov));
		break;
	default:
		break;
	}
	this->x = x;
	this->y = y;*/
}
