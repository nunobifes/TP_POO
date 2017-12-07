#include <fstream>
#include <iostream>
#include <string>


#include "Consola.h"
#include "Utilizador.h"

using namespace std;


int main()
{
	bool ready=true;
	int op, linha = 0, coluna = 0;
	string comando;

	//Ciclo inicial de configuração, vamos abrir o ficheiro para ler os comandos que lá temos
	do {
		Consola::gotoxy(2, 47);
		cout << "Comando: ";
		getline(cin, comando);
		Consola::clrscr();
		istringstream iss(comando);
		iss >> comando;

		op = cmd_op(comando);
		switch (op) {
		case 1:
			iss >> linha;
			iss >> coluna;
			
			if (linha < 10 || coluna < 10) {
				Consola::setTextColor(Consola::VERMELHO_CLARO);
				Consola::gotoxy(45, 35);
				cout << "[ERRO] - Mapa demasiado pequeno!!" << endl;
				Consola::setTextColor(Consola::BRANCO);
				linha = 0; coluna = 0;
				break;
			}
			
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			break;

		}
	} while (ready);
}