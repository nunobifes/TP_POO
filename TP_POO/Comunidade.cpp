#include "Comunidade.h"
#include "Formiga_Tipo.h"
#include "Consola.h"

int Comunidade::conta = 1;

Comunidade::Comunidade(Mundo* m, int cor)
	:cor(cor)
{
	id = conta++;
	ni = new Ninho(id, m->get_energia_ninho(), m->get_posx_ninho(), m->get_posy_ninho(), false ,this, m);
}

Comunidade::Comunidade(Comunidade& c)
{
	cor = c.cor;
	id = c.id;
	ni = new Ninho(*c.ni);
	for (auto i = 0; i < c.form.size(); i++)
	{
		Formiga *formi = c.form.at(i)->duplica();
		form.push_back(formi);
	}
	conta = c.conta;
}

int Comunidade::get_cor() const
{
	return cor;
}

int Comunidade::get_id() const
{
	return id;
}

void Comunidade::reset_id()
{
	conta = 1;
}

void Comunidade::add_formiga(int lim, char t, int x, int y)
{
	if(t != 0)
	{
		Formiga* fo;
		if (t == 'C') {
			fo = new Cuidadora(x, y, lim, id);
		}
		else if (t == 'V') {
			fo = new Vigilante(x, y, lim, id);
		}
		else if (t == 'A') {
			fo = new Assaltante(x, y, lim, id);
		}
		else if (t == 'E') {
			fo = new Exploradora(x, y, lim, id);
		}
		

		if(x < 0 && y < 0)
		{
			int xr = (rand() % lim);
			int yr = (rand() % lim);
			fo->set_posX(xr);
			fo->set_posY(yr);
		}
		// corrigir
		form.push_back(fo);



	}
	else
	{
		int randT = rand() % 4;
		Formiga * fo;
		switch(randT)
		{
		case 0:
			fo = new Cuidadora(ni->getPosX(), ni->getPosY(), lim, id);
			form.push_back(fo);
			break;
		case 1:
			fo = new Vigilante(ni->getPosX(), ni->getPosY(), lim, id);
			form.push_back(fo);
			break;
		case 2:
			fo = new Assaltante(ni->getPosX(), ni->getPosY(), lim, id);
			form.push_back(fo);
			break;
		case 3:
			fo = new Exploradora(ni->getPosX(), ni->getPosY(), lim, id);
			form.push_back(fo);
			break;
		default:
			break;

		}

	}
	
}


void Comunidade::modo_guerra(bool g)
{
	
	if (ni->get_guerra() == g)
	{
		Consola::setTextColor(Consola::VERMELHO);
		Consola::gotoxy(2, 13);
		cout << "Ninho ja se encontra no modo pretendido!" << endl;
		Consola::setTextColor(Consola::BRANCO);
	}
	else if (g)
		ni->setGuerra(g);
	else if (!g)
		ni->setGuerra(g);
	else
		;
}

void Comunidade::mata_formiga(int x, int y)
{
	for (auto i = 0; i < form.size(); i++)
	{
		if(x == form.at(i)->get_posX() && y == form.at(i)->get_posY())
		{
			form.erase(form.begin()+i);
		}
	}
}

/*void Comunidade::comeu_migalha()
{
	
	for (auto i = 0; i<get_formiga().size(); i++)
	{
		Formiga * f = get_formiga().at(i);
		f->comeu_migalha();

	}
}*/

string Comunidade::lista_info() const
{
	string info;
	ostringstream oss;
	oss << "ID: " << this->id << " Cor: " << this->cor << " Num Formigas: " << form.size() << endl;
	info = oss.str();

	return info;
}


Comunidade::~Comunidade()
{
	//delete ni;
	for (auto i = 0; i < form.size(); i++)
		delete form[i];
}
