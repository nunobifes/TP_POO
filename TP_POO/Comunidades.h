#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>

class Ninhos;
class Formiga;

using namespace std;

class Comunidades {
	Ninhos* ni;
	Formiga *form;

	vector<Formiga*> v;

public:
	Comunidades(Ninhos *id, Ninhos *cor);
		
};
