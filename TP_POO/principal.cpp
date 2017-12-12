#include <fstream>
#include <iostream>
#include <string>


#include "Consola.h"
#include "Utilizador.h"
#include "Mundo.h"

using namespace std;


int main()
{
	bool ready = true;
	int op, linha = 0, coluna = 0, energia = 0;
	string comando;
	mundo** campo = nullptr;
	

	// "Menu" inicial de configuração 
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
				int o = 0;
				break;
			}
			else {
				campo = new mundo*[linha];
				for(int i = 0; i <= linha; i++){
					campo[i] = new mundo[coluna];
					for (int j = 0; j <= coluna; j++) {
						campo[i][j].setCenas(' ');
						//campo[i][j].setNinho(nullptr);
						//campo[i][j].setFormigas(nullptr);
						//campo[i][j].setComunidade(nullptr);
					}

					break;
				}

		case 2:
			//Definir a energia...



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
		}
	} while (ready);

}