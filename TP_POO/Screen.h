

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

#include "Consola.h"

using namespace std;

int cmd_op(string s) {
	int op = 0;
	if (!s.compare("defmundo"))
		op = 1;
	else if (!s.compare("defen"))			//funciona como o introduzir o numero de moedas no tp ano passado
		op = 2;
	else if (!s.compare("defpc"))
		op = 3;
	else if (!s.compare("defmi"))
		op = 4;
	else if (!s.compare("defme"))
		op = 5;
	else if (!s.compare("defnm"))
		op = 6;
	else if (!s.compare("inicio"))
		op = 7;
	else if (!s.compare("guarda"))
		op = 8;
	else if (!s.compare("muda"))
		op = 9;
	else if (!s.compare("apaga"))
		op = 10;
	else if (!s.compare("sair"))
		op = 11;
	return op;
}


