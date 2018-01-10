#include "Mundo.h"



// CONSTRUTOR
Mundo::Mundo(int l, int et)
	: lim_max(l), energia_transf(et)
{
	cconta = 0;
	preenche_cor_vector();
}

Mundo::Mundo(Mundo& m)
{
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


void Mundo::set_nome(string n)
{
	this->nome = n;
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

string Mundo::get_nome() const
{
	return nome;
}

// FUNCOES
void Mundo::cria_comunidade()
{
	Comunidade *c = new Comunidade(this, cor.at(cconta));
	co.push_back(c);
	cconta++;
}
void Mundo::cria_migalha(int x, int y)
{
	int perc;
	if(mig.size() == 0)
	{
		perc = ((lim_max*lim_max)*m_per_inicial) / 100;

		for(auto i = 0; i < perc; i++)
		{
			int xr = (rand() % lim_max);
			int yr = (rand() % lim_max);

			Migalha* miga = new Migalha(m_e_inicial, xr, yr);
			mig.push_back(miga);
		}
	}
	else if(x > -1 && y > -1)
	{
		Migalha* miga = new Migalha(m_e_inicial, x, y);
		mig.push_back(miga);
	}
	else
	{
		perc = rand() % m_max;
		for (auto i = 0; i < perc; i++)
		{
			int xr = (rand() % lim_max);
			int yr = (rand() % lim_max);

			Migalha* miga = new Migalha(m_e_inicial, xr, yr);
			mig.push_back(miga);
		}
	}
	
}

void Mundo::avanca_tempo(int vezes)
{
	if (vezes < 1)
		vezes = 1;
	for (auto v = 0; v < vezes; v++) {

		for (auto i = 0; i < get_comunidade().size(); i++)
		{
			// NINHOS
			Comunidade *comu = get_comunidade().at(i);

			//FORMIGAS
			for (auto j = 0; j < comu->get_formiga().size(); j++)
			{
				Formiga* form = comu->get_formiga().at(j);
				form->anda();
				
			}
			
		}
		comeu_migalha();
		cria_migalha(-1, -1);
		
	}
	
}

void Mundo::comeu_migalha()
{
	for (auto i = 0; i < get_comunidade().size(); i++)
	{
		Comunidade* c = get_comunidade().at(i);
		for(auto j = 0; j < c->get_formiga().size(); j++)
		{
			Formiga* f = c->get_formiga().at(j);
			for(auto k = 0; k < get_migalha().size(); k++)
			{
				mig.at(k);
				if((mig.at(k)->get_posx() == f->get_posX()) && (mig.at(k)->get_posy() == f->get_posY()))
				{
					mig.erase(mig.begin() + k);
					f->contr_energia(m_e_inicial);
				}
			}
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

void Mundo::elimina_comunidade(int n)
{
	for (int i = 0; i < co.size(); i++)
	{
		if (n == co.at(i)->get_id())
		{
			co.erase(co.begin() + i);
		}

	}
}

// DESTRUTOR
Mundo::~Mundo()
{
	co.clear();
	mig.clear();
	cor.clear();
	
}
