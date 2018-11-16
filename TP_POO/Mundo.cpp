#include "Mundo.h"


// CONSTRUTOR
Mundo::Mundo(int l, int et)
	: lim_max(l), energia_transf(et)
{
	cconta = 0;
	ite = 0;
	preenche_cor_vector();
}

Mundo::Mundo(Mundo& m)
{

	*this = m;
	
}

Mundo&Mundo::operator=(const Mundo& m)
{
	if (this == &m)
		return *this;

	for (auto i : co)
		delete i;
	co.clear();

	for (auto i : mig)
		delete i;
	mig.clear();

	for (auto i = 0; i < m.cconta; i++)
	{
		Comunidade *com = new Comunidade(*m.co.at(i));
		co.push_back(com);
	}
	for (auto i = 0; i <m.mig.size(); i++)
	{
		Migalha *mi = new Migalha(*m.mig.at(i));
		mig.push_back(mi);
	}

	cor = m.cor;
	cconta = m.cconta;
	energia_ninho = m.energia_ninho;
	perc_energia = m.perc_energia;
	energia_transf = m.energia_transf;
	m_e_inicial = m.m_e_inicial;
	m_per_inicial = m.m_per_inicial;
	m_max = m.m_max;
	nome = m.nome;
	lim_max = m.lim_max;


	return *this;
	
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
int Mundo::get_energ_perc() const
{
	return perc_energia;
}
int Mundo::get_energ_transf() const
{
	
	return energia_transf;
}

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

int Mundo::get_ite() const
{
	return ite;
}

void Mundo::add_energia_ninho(int n, int e)
{
	for(auto i = 0; i < co.size(); i++)
	{
		if(co.at(i)->get_ninho()->get_id() == n)
			co.at(i)->get_ninho()->contr_energia(e);
	}
}

void Mundo::add_energia_formiga(int x, int y, int e)
{
	for (auto i = 0; i < co.size(); i++)
	{
		Comunidade* c = co.at(i);
		for(auto j = 0; j < c->get_formiga().size(); j++)
		{
			Formiga* f = c->get_formiga().at(j);
			if (f->get_posX() == x && f->get_posY() == y)
				f->contr_energia(e);
		}
		
	}
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
			Comunidade *comu = get_comunidade().at(i);
			comu->avanca(this);
		}
		for(auto i = 0; i < get_migalha().size(); i++)
		{
			Migalha* mig = get_migalha().at(i);
			if (mig->get_energia() <= (mig->get_energiaB()*0.1))
				apaga_migalha(mig);
			
			mig->set_energia(mig->get_energia() - 1);
		}
		cria_migalha(-1, -1);
		ite++;
	}
	
}

void Mundo::modo_guerra(int n, int ni)
{
	

	

	Comunidade *cini = nullptr;
	for (auto i = 0; i < get_comunidade().size(); i++)
	{
		cini = get_comunidade().at(i);
		if (cini->get_id() == ni && cini->get_guerra() == nullptr)
			break;
		if (i == get_comunidade().size() && cini->get_guerra() == nullptr)
			ni = 0;
	}



	for(auto i = 0; i < get_comunidade().size(); i++)
	{
		Comunidade *c = get_comunidade().at(i);
		if (ni == 0)
		{
			if(c->get_guerra()!=nullptr)
			{
				c->modoPaz();
				break;
			}
				
		}
		else if (c->get_id() == n && c->get_guerra()==nullptr) {

			c->setGuerra(cini);
			cini->setGuerra(c);
		}
	}
}


void Mundo::apaga_migalha(Migalha *miga)
{
	for (auto i = 0; i < mig.size(); i++)
	{
		if (mig.at(i) == miga)
			mig.erase(mig.begin() + i);
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

string Mundo::lista_info() const
{
	string info;
	ostringstream oss;
	oss << "Nome: " << "Default" << " Num Comunidades: " << co.size() << " Num Migalhas " << mig.size() << endl;
	info = oss.str();

	return info;
}


// DESTRUTOR
Mundo::~Mundo()
{
	for (auto i = 0; i < co.size(); i++)
		delete co[i];

	for (auto i = 0; i < mig.size(); i++)
		delete mig[i];
	
}
