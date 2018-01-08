#ifndef __MUNDO__
#define __MUNDO__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>

#include "Comunidade.h"
#include "Migalha.h"

class Comunidade;

class Mundo {

	
	vector <Comunidade*> co;
	vector <Migalha*> mig;
	vector <int> cor;
	static int cconta;
	int lim_max;
	int energia_ninho;
	int perc_energia;
	int energia_transf;
	int ninho_x, ninho_y;
	int m_e_inicial;
	int m_per_inicial;
	int m_max;

public:
	Mundo(int l, int et);

	void setLim(int l);
	void set_energ_ninho(int e);
	void set_perc_energ(int pe);
	void set_energ_transf(int et);
	void set_ninho_xy(int x, int y);
	void set_m_e_inical(int me);
	void set_m_per_inicial(int mpe);
	void set_m_max(int mm);
	
	int get_energia_ninho() const;
	int get_posx_ninho() const;
	int get_posy_ninho() const;
	int get_lim() const;
	vector<Comunidade*> get_comunidade() const;
	vector<Migalha*> get_migalha() const;
	int get_m_e_inical() const;
	int get_m_per_inicial() const;
	int get_m_max() const;

	void cria_comunidade();
	void cria_migalha();
	void preenche_cor_vector();

	~Mundo();
};

#endif