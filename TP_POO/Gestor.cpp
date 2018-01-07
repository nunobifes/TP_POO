#include "Gestor.h"


Gestor::Gestor() : m(10, 1) {}

void Gestor::run() {
	// configuracao
	bool ready = true;
	Consola::setScreenSize(50, 140);
	while (ready) {
		s.margens();
		s.intro();
		if (c.menu_config(&m, &s))
			ready = false;
	}

	m.cria_migalha();
	// simulacao
	ready = true;
	while (ready) {
		s.margens();
		s.intro_sim();
		s.mostra_mapa();
		s.desenha(&m);
		if (c.menu_simul(&m, &s))
			ready = false;
	}
}
