#ifndef __COMANDOS__
#define __COMANDOS__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <fstream>

#include "Consola.h"
#include "Screen.h"


class Mundo;

class Comandos
{
public:
	bool menu_config(Mundo* m, Screen* s)const;

	bool menu_simul(vector <Mundo*> *saves, Mundo** ppm, Screen* s)const;
	
};

#endif