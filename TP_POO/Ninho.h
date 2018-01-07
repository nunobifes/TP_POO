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
	static char ident;
	static int conta;
	int id;						// Atraves do id do ninho a formiga sabe a que ninho pertence....
	int energia;
	int x, y;

public:

	Ninho(int e, int x, int y, Comunidade* c, Mundo* m);




	int getId() const { return id; }
	int getEnergia() const { return energia; }
	int getPosX() { return x; }
	int getPosY() { return y; }

	void set_comunid(Comunidade* c);
	void set_mundo(Mundo* m);

	//void setId(int i);
	void setEnergia(int e);


	void setPosX(int x);
	void setPosY(int y);


	int get_id() const;

	~Ninho();



};

#endif
