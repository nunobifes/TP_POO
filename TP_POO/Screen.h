#ifndef __SCREEN__
#define __SCREEN__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include "Mundo.h"

using namespace std;

class Screen
{
public:
	int cmd_op(string s);
	int cmd_sim_op(string s);

	void mostra_mapa();
	void desenha(Mundo* m);

	void margens();
	void intro();
	void intro_sim();	
};

#endif