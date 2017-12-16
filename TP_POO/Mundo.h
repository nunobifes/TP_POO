#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>


using namespace std;

class Ninhos;
class Formiga;

class Mundo {

	Ninhos* ni;
	Formiga* form;
	
public:
	Mundo();

	Ninhos* getNinho() {return ni;}
	Formiga* getFormiga() {return form;}

	void setNinho(Ninhos* ni);
	void setFormiga(Formiga* form);

	~Mundo();

	
};



