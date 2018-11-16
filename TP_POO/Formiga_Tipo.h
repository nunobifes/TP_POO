	#ifndef __TIPO__
#define __TIPO__
#include <string>
#include <iostream>
#include <sstream>

#include "Formiga.h"
#include "RegraAssalta.h"
#include "RegraFoge.h"
#include "RegraComeMigalha.h"
#include "RegraProcuraMigalha.h"
#include "RegraVaiParaNinho.h"
#include "RegraPasseia.h"
#include "RegraProtege.h"
#include "RegraPersegue.h"
#include "RegraAtacaInimigas.h"
#include "RegraVaiPara.h"
#include "RegraProtegida.h"

class Cuidadora : public Formiga
{

public:
	Cuidadora(int x, int y, int lim, int id)
		:Formiga(100, 5, 3, 'C', x, y, lim, id)
	{
		reg.push_back(new RegraFoge);
		reg.push_back(new RegraComeMigalha);
		reg.push_back(new RegraProcuraMigalha);
		reg.push_back(new RegraVaiParaNinho);
		reg.push_back(new RegraPasseia);

		
	}

	Formiga *duplica() const override
	{
		return new Cuidadora(*this);
	}

};


class Vigilante : public Formiga
{
public:
	Vigilante(int x, int y, int lim, int id)
		:Formiga(150, 7, 5, 'V', x, y, lim, id)
	{
		//reg.push_back(new RegraProtege);
		reg.push_back(new RegraComeMigalha);
		reg.push_back(new RegraProcuraMigalha);
		reg.push_back(new RegraPasseia);
	}

	Formiga *duplica() const override
	{
		return new Vigilante(*this);
	}
};


class Assaltante : public Formiga
{
public:
	Assaltante(int x, int y, int lim, int id)
		:Formiga(80, 8, 4, 'A', x, y, lim, id)
	{
		reg.push_back(new RegraAssalta);
		reg.push_back(new RegraPersegue);
		reg.push_back(new RegraComeMigalha);
		reg.push_back(new RegraProcuraMigalha);
		reg.push_back(new RegraPasseia);	
	}

	Formiga *duplica() const override
	{
		return new Assaltante(*this);
	}
};


class Exploradora : public Formiga
{
public:
	Exploradora(int x, int y, int lim, int id)
		:Formiga(200, 10, 8, 'E', x, y, lim, id)
	{
		//reg.push_back(new RegraProtegida);
		reg.push_back(new RegraComeMigalha);
		reg.push_back(new RegraPasseia);
	}

	Formiga *duplica() const override
	{
		return new Exploradora(*this);
	}
};


class Soldado : public Formiga
{
public:
	Soldado(int x, int y, int lim, int id)
		:Formiga(80, 8, 4, 'S', x, y, lim, id)
	{
		reg.push_back(new RegraAtacaInimigas);
		reg.push_back(new RegraVaiPara);
		reg.push_back(new RegraAssalta);
		reg.push_back(new RegraPasseia);
	}

	Formiga *duplica() const override
	{
		return new Soldado(*this);
	}
};


class Surpresa : public Formiga
{
public:
	Surpresa(int x, int y, int lim, int id)
		:Formiga(0, 0, 0, 'X', x, y, lim, id)
	{
		
	}

	Formiga *duplica() const override
	{
		return new Surpresa(*this);
	}
};

#endif

