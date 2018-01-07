#include "Comunidade.h"

Comunidade::Comunidade(Mundo* m)
{
	ni = new Ninho(m->get_energia_ninho(), m->get_posx_ninho(), m->get_posy_ninho(), this, m);
	
}


void Comunidade::add_formiga_at(char t, int x, int y)
{
	Formiga* fo = new Formiga(t, x, y);
	form.push_back(fo);
}
