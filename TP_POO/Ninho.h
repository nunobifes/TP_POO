#ifndef __NINHO__
#define __NINHO__


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>


using namespace std;

//class Formiga;
class Comunidade;
class Mundo;
class Formiga;


class Ninho {
	int id;						// Atraves do id do ninho a formiga sabe a que ninho pertence....
	int energia;
	int e_base;
	int x, y;
	

public:

	Ninho(int id, int e, int x, int y);
	Ninho(Ninho& n);


	int getEnergia() const { return energia; }
	int getPosX() { return x; }
	int getPosY() { return y; }


	//void setId(int i);
	void setEnergia(int e);
	void setId(int e);
	void setPosX(int x);
	
	void setPosY(int y);


	int get_id() const;

	

	int get_energia_b() const;
	double da_energia(Mundo* m, Comunidade* c, Formiga* f);
	void contr_energia(int ener);
	void ModoGuerra();
	string lista_info() const;

	~Ninho();
	
};

#endif
