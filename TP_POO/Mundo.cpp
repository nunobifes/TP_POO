#include "Mundo.h"


int Mundo::cconta = 0;
// CONSTRUTOR
Mundo::Mundo(int l, int et)
	: lim_max(l), energia_transf(et)
{
	preenche_cor_vector();
}

// SET'S
void Mundo::setLim(int l)
{
	this->lim_max = l;
}
void Mundo::set_energ_ninho(int e)
{
	this->energia_ninho = e;
}
void Mundo::set_perc_energ(int pe)
{
	this->perc_energia = pe;
}
void Mundo::set_energ_transf(int et)
{
	this->energia_transf = et;
}
void Mundo::set_ninho_xy(int x, int y)
{
	this->ninho_x = x;
	this->ninho_y = y;
}
void Mundo::set_m_e_inical(int me)
{
	this->m_e_inicial = me;
}
void Mundo::set_m_per_inicial(int mpe)
{
	this->m_per_inicial = mpe;
}
void Mundo::set_m_max(int mm)
{
	this->m_max = mm;
}

// GET'S
int Mundo::get_lim() const
{
	return lim_max;
}
int Mundo::get_energia_ninho() const
{
	return energia_ninho;
}
int Mundo::get_posx_ninho() const
{
	return ninho_x;
}
int Mundo::get_posy_ninho() const
{
	return ninho_y;
}
vector<Comunidade*> Mundo::get_comunidade() const
{
	return co;
}
vector<Migalha*> Mundo::get_migalha() const
{
	return mig;
}
int Mundo::get_m_e_inical() const
{
	return m_e_inicial;
}
int Mundo::get_m_per_inicial() const
{
	return m_per_inicial;
}
int Mundo::get_m_max() const
{
	return m_max;
}

// FUNCOES
void Mundo::cria_comunidade()
{
	Comunidade *c = new Comunidade(this, cor.at(cconta));
	co.push_back(c);
	cconta++;
}
void Mundo::cria_migalha()
{
	if(mig.size() == 0)
	{
		int perc;
		perc = ((lim_max*lim_max)*m_per_inicial) / 100;

		for(auto i = 0; i < perc; i++)
		{
			int x = (rand() % lim_max) + 59;
			int y = (rand() % lim_max) + 18;

			Migalha* miga = new Migalha(m_e_inicial, x, y);
			mig.push_back(miga);
		}
	}
	
}
void Mundo::preenche_cor_vector()
{
	for(auto i = 1; i<11; i++)
	{
		if (i == 2)
			cor.push_back(i + 10);
		else if (i == 10)
			cor.push_back(i + 1);
		else
			cor.push_back(i);
	}
}
// DESTRUTOR
Mundo::~Mundo()
{

}
