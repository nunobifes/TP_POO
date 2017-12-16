#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

class Ninhos;

class Formiga {
	Ninhos *ident;				//número de identificação da formiga
	int energia;
	int visao_form;
	int mov_form;
	int x, y;
	//Variação de energica, só com as migalhas

	//Ninhos *p;
public:
	Formiga(Ninhos* id, int e, int vi, int m)
		:ident(id), energia(e), visao_form(vi), mov_form(m) {}

	Ninhos* getId()const { return ident; }
	int getEnergia()const { return  energia; }
	int getVisao() const { return visao_form; }
	int getMove()const { return mov_form; }

	int getPosX() { return x; }
	int getPosY() { return y; }

	void setID(int id);
	/*virtual*/ void setEnergia(int e);
	void setVisao(int vi);
	void setMove(int m);

	void setPosX(int x);
	void setPosY(int y);

	//void LigaNinho(Ninhos *n) { p = n; }

	

};

