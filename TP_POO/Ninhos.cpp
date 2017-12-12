//Um ninho serve essencialmente para criar 
//novas formigas e também como refúgio de algumas das formigas existentes na sua comunidade.


#include "Ninhos.h"

void ninho::setId(char i) {
	this->id = i;
}

void ninho::setEnergia(int e) {
	this->energia = e;
}

void ninho::setCoord(int l, int c) {
	this->linha = l;
	this->coluna = c;

}

ninho::~ninho() {

}