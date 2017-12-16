#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

class Formiga;

class Ninhos {
	int id;						// Atraves do id do ninho a formiga sabe a que ninho pertence....
	int energia;
	int x, y;
	

public:

	Ninhos(int id, int e, int x, int y)
		:id(id), energia(e), x(x), y(y){}			

	int getId() const { return id; }
	int getEnergia() const { return energia; }
	int getPosX() { return x; }
	int getPosY() { return y; }

	void setId(int i);
	void setEnergia(int e);
	//void setCoord(int l, int c);

	void setPosX(int x);
	void setPosY(int y);
	

	void insereNinho(Formiga *fr);

	~Ninhos();



};