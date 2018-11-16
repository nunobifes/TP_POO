//Um ninho serve essencialmente para criar 
//novas formigas e tamb�m como ref�gio de algumas das formigas existentes na sua comunidade.

#include "Formiga.h"
#include "Ninho.h"
#include "Mundo.h"

//char Ninho::ident = 'N';

Ninho::Ninho(int id, int e, int x, int y)
:id(id),energia(e), x(x), y(y)
{

	e_base = energia;
	
}

Ninho::Ninho(Ninho& n)
{
	id = n.id;
	energia = n.energia;
	x = n.x;
	y = n.y;
	
	
	e_base = n.e_base;
}



void Ninho::setEnergia(int e) {
	this->energia = e;
}


void Ninho::setPosX(int x) {
	this->x = x;
}


void Ninho::setPosY(int y) {
	this->y = y;
}

int Ninho::get_id() const
{
	return id;
}



int Ninho::get_energia_b() const
{
	return e_base;
}


void Ninho::contr_energia(int ener)
{
	this->energia += ener;
}




string Ninho::lista_info() const
{
	string info;
	ostringstream oss;
	oss << "Energia: " << this->energia << " PosX: " << this->x << " PosY: " << this->y << " Guerra: " << endl;
	info = oss.str();

	return info;
}


double Ninho::da_energia(Mundo* m, Comunidade* c, Formiga* f)
{
	double energiaf = f->get_energia();
	double energiafb = f->get_energiab();
	int energ_transf = m->get_energ_transf();

	if(energiaf < (energiafb*0.5))
	{
		if(energia > energ_transf)
		{
			f->contr_energia(energ_transf);
			this->energia -= energ_transf;
		}
		
	}
	else if(energiaf > energiafb)
	{
		f->contr_energia((-1)*energ_transf);
		this->energia += energ_transf;
	}

	return energia;
}



Ninho::~Ninho() {


}
