#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>

#include "Formiga.h"

using namespace std;

class ninho {
	char id;						// Atraves do id do ninho a formiga sabe a que ninho pertence....
	int energia;
	int linha = 0, coluna = 0;

	//vector< formiga* > v;

public:

	ninho(int id, int e)
		:id(id), energia(e){}

	char getId() const { return id; }
	int getEnergia() const { return energia; }

	void setId(char i);
	void setEnergia(int e);
	void setCoord(int l, int c);
	

	//void ligaNinho(ninho *a) { p = a; }

	~ninho();



};