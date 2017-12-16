#include "Comunidades.h"

//Cada comunidade, possui o seu próprio ninho

Comunidades::Comunidades(Ninhos *id, Ninhos *cor)
{
		form = new Formiga(id, 0, 0, 0);
			v.push_back(form);						//Não consigo descobrir este erro...
}
