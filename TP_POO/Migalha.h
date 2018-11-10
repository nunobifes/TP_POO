#ifndef __MIGALHA__
#define __MIGALHA__

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

class Migalha
{
	int energia;
	int x;
	int y;

public:
	
	Migalha(int e, int x, int y);

	Migalha(Migalha & mig);

	void set_energia(int e);
	void set_posx(int x);
	void set_posy(int y);

	int get_energia() const;
	int get_posx() const;
	int get_posy() const;

	string lista_info() const;

};

#endif