#include "RegraComeMigalha.h"
#include "Mundo.h"

RegraComeMigalha::RegraComeMigalha()
{
	continua = false;
	miga = nullptr;
}

RegraComeMigalha::~RegraComeMigalha()
{
}

bool RegraComeMigalha::verificaCondicao(Mundo * m, Formiga * form)
{
	miga = nullptr;
	int x = form->get_posX();
	int y = form->get_posY();
	double energia = form->get_energia();
	double energiab = form->get_energiab();
	if (energia <= energiab || energia >= (energiab / 2)) {

		for (auto i = 0; i < m->get_migalha().size(); i++)
		{
			Migalha *temp = m->get_migalha().at(i);

			if (temp->get_posx() == x + 1 && temp->get_posy() == y) {
				if (miga == nullptr || miga < temp)
					miga = temp;

			}
			else if (temp->get_posx() == x - 1 && temp->get_posy() == y) {
				if (miga == nullptr || miga < temp)
					miga = temp;
			}
			else if (temp->get_posx() == x && temp->get_posy() == y + 1) {
				if (miga == nullptr || miga < temp)
					miga = temp;
			}
			else if (temp->get_posx() == x && temp->get_posy() == y - 1) {
				if (miga == nullptr || miga < temp)
					miga = temp;
			}
			else if (temp->get_posx() == x && temp->get_posy() == y) {
				if (miga == nullptr || miga < temp)
					miga = temp;
			}
		}
		if (miga == nullptr)
			return false;
		else
			return true;
	}
	else
		return false;
}

void RegraComeMigalha::Accao(Mundo * m, Formiga * form)
{



	double energ = miga->get_energia();
	if (energ <= m->get_m_e_inical()*0.1)
	{
		form->set_energia(form->get_energia() + energ);
		miga->set_energia(0);

	}
	else
	{
		form->set_energia(form->get_energia() + energ*0.5);
		miga->set_energia(energ - energ*0.5);
	}


	if (miga->get_energia() == 0) {
		m->apaga_migalha(miga);
	}


}
