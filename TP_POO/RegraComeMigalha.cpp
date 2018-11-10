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

	int x = form->get_posX();
	int y = form->get_posY();
	
	for(auto i = 0; i < m->get_migalha().size(); i++)
	{
		Migalha *temp = m->get_migalha().at(i);
		
		if (temp->get_posx() == x + 1 && temp->get_posy() == y) {
			if (miga == nullptr || miga < temp)
				miga = temp;

		}
		else if (temp->get_posx() == x - 1 && temp->get_posy() == y){
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

	/*Migalha *miga = nullptr;
	int raio_visao = form->get_visao();
	bool flag = false;

	int vxs = form->get_posX() + raio_visao;
	int vys = form->get_posY() + raio_visao;

	int vxi = form->get_posX() - raio_visao;
	int vyi = form->get_posY() - raio_visao;

	for (auto j = 0; j < m->get_migalha().size(); j++)
	{

		Migalha * mig = m->get_migalha().at(j);
		for (int i = 0; i < raio_visao; i++) {

			if (mig->get_posx() != vxs + i && mig->get_posy() != vys + i)
				if (mig->get_posx() != vxi - i && mig->get_posy() != vyi - i)
					if (mig->get_posx() != vxs + i && mig->get_posy() != vyi - i)
						if (mig->get_posx() != vxi - i && mig->get_posy() != vys + i)
							;
			if (miga == nullptr || mig->get_energia() > miga->get_energia()) {
				miga = mig;
				break;
			}
		}
		
	}

	int posXfor = form->get_posX();
	int posYfor = form->get_posY();

	int posXmig = miga->get_posx();
	int posYmig = miga->get_posy();

	if (posXfor == posXmig && posYfor == posYmig)
		return true;
	else {
		if (posXfor == posXmig && (posYfor == posYmig - 1 || posYfor == posYmig + 1))
			return true;
		else {
			if (posYfor == posYmig && (posXfor == posXmig - 1 || posXfor == posXmig + 1))
				return true;
		}
	}

	return false;*/
}

void RegraComeMigalha::Accao(Mundo * m, Formiga * form)
{


	
		int energ = miga->get_energia();
		form->set_energia(form->get_energia() + ((m->get_m_per_inicial()/10) * energ));
		miga->set_energia(energ - ((m->get_m_per_inicial()/10) * energ));

		if (miga->get_energia() < 1)
			delete miga;
	
	
}

Regra * RegraComeMigalha::duplica() const
{
	return new RegraComeMigalha(*this);
}
