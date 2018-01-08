#ifndef __TIPO__
#define __TIPO__
#include <string>
#include <iostream>
#include <sstream>

#include "Formiga.h"

class Cuidadora : public Formiga
{
public:
	Cuidadora(int x, int y)
		:Formiga(100, 5, 3, 'C', x, y)
	{
		
	}
};


class Vigilante : public Formiga
{
public:
	Vigilante(int x, int y)
		:Formiga(150, 7, 5, 'V', x, y)
	{
		
	}
};


class Assaltante : public Formiga
{
public:
	Assaltante(int x, int y)
		:Formiga(80, 8, 4, 'A', x, y)
	{
		
	}
};


class Exploradora : public Formiga
{
public:
	Exploradora(int x, int y)
		:Formiga(200, 10, 8, 'E', x, y)
		{}
};

class Surpresa : public Formiga
{
public:
	Surpresa(int x, int y)
		:Formiga(0, 0, 0, 'S', x, y)
		{}
};

#endif

