//Um ninho serve essencialmente para criar 
//novas formigas e também como refúgio de algumas das formigas existentes na sua comunidade.


#include "Ninhos.h"
#include "Formiga.h"


void Ninhos::setId(int i) {
	this->id = i;
}

void Ninhos::setEnergia(int e) {
	this->energia = e;
}

/*void Ninhos::insereNinho(Formiga *fr) {
	v.push_back(fr);
	fr->LigaNinho(this);

}*/

void Ninhos::setPosX(int x) {
	this->x = x;
}

void Ninhos::setPosY(int y) {
	this->y = y;
}

Ninhos::~Ninhos() {

}