#include "Comunidades.h"

//Cada comunidade, possui o seu pr�prio ninho

Comunidades::Comunidades(Ninhos *id, Ninhos *cor)
{
		form = new Formiga(id, 0, 0, 0);
			v.push_back(form);						//N�o consigo descobrir este erro...
}
