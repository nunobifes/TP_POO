#ifndef __GESTOR__
#define __GESTOR__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <fstream>

#include "Mundo.h"
#include "Comandos.h"
#include "Screen.h"
#include "Migalha.h"

class Gestor {
	Mundo * m;
	vector <Mundo *> saves;
	Comandos c;
	Screen s;
	

public:
	Gestor();
	void run();
	~Gestor();

};

#endif