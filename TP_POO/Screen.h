

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

//#include "Consola.h"
//#include "Mundo.h"

class Mundo;

int cmd_op(string s);
int cmd_sim_op(string s);

void mostra_mapa(int linha, int coluna, Mundo **campo);

void margens();

void intro();
void intro_sim();