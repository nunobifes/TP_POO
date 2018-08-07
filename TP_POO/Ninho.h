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


class Ninho {
	Comunidade* cn;
	Mundo* mn;
	int id;						// Atraves do id do ninho a formiga sabe a que ninho pertence....
	int energia;
	int e_base;
	int x, y;
	bool guerra;

public:

	Ninho(int id, int e, int x, int y, bool g, Comunidade* c, Mundo* m);




	
	int getEnergia() const { return energia; }
	int getPosX() { return x; }
	int getPosY() { return y; }

	void set_comunid(Comunidade* c);
	void set_mundo(Mundo* m);

	//void setId(int i);
	void setEnergia(int e);
	void setId(int e);
	void setPosX(int x);
	void setGuerra(bool g);
	void setPosY(int y);


	int get_id() const;

	bool get_guerra() const;

	int get_energia_b() const;

	void contr_energia(int ener);
	void ModoGuerra();
	string lista_info() const;

	~Ninho();



};

#endif
