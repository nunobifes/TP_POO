#include "Gestor.h"


Gestor::Gestor() : m(new Mundo(10, 1)) {}

// tem que ter destrutor


void Gestor::run() {
	// configuracao
	while (true) {
		bool ready = true;
		Consola::setScreenSize(50, 140);
		while (ready) {
			s.margens();
			s.intro();
			if (c.menu_config(m, &s))
				ready = false;
		}

		m->cria_migalha(-1, -1);
		// simulacao
		ready = true;
		while (ready) {
			s.margens();
			s.intro_sim();
			s.mostra_mapa(m);
			s.desenha(m);
			if (c.menu_simul(&saves ,&m, &s))
				ready = false;
			}
		//m = new Mundo(10, 1);
	}
}

Gestor::~Gestor()
{
	delete m;
	//delete mc;
}
