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
	static int cmd_op(string s);
	static int cmd_sim_op(string s);

	static void mostra_mapa(Mundo* m);
	static void desenha(Mundo* m);
	static void mostra_info(Mundo* m);
	static int corrige_posX(int x);
	static int corrige_posY(int y);
	static void margens();
	static void intro();
	static void intro_sim();
	static void lista_mundo(Mundo** m);
	static void lista_ninho(Mundo** m, int n);
	static void lista_posicao(Mundo** m, int x, int y);

};

#endif