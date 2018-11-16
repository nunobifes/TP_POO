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
	double energia;
	double energ_b;
	int x;
	int y;

public:
	
	Migalha(double e, int x, int y);

	Migalha(Migalha & mig);

	void set_energia(double e);
	void set_posx(int x);
	void set_posy(int y);

	double get_energia() const;
	double get_energiaB() const;
	int get_posx() const;
	int get_posy() const;

	string lista_info() const;

};

#endif