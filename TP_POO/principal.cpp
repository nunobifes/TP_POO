#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <fstream>
#include "Comandos.h"
#include "Gestor.h"



//Fazer os includes necessários

Gestor* c;

int main() {
	c = new Gestor;
	
	c->run();

	return 0;
}