
#include "Consola.h"
#include "Screen.h"
#include "Mundo.h"
#include "Screen.h"
#include "Comunidades.h"
#include <fstream>

using namespace std;


int main()
{
	int flag_energia = 0, flag_dim = 0, ready = 0;
	
	int op, linhas = 0, energia = 0, energia_i = 0, energia_t = 0, pos_miga = 0, energia_miga = 0, max_miga = 0;
	vector <Ninhos *> ninhos;
	string comando;
	Mundo** campo = nullptr;
	

	// "Menu" inicial de configuração 
	do {
		Consola::setScreenSize(50, 140);
		
		margens();
		intro();
		Consola::gotoxy(2, 47);
		cout << "Comando de configuracao: ";
		getline(cin, comando);
		Consola::clrscr();
		istringstream iss(comando);
		iss >> comando;

		op=cmd_op(comando);
		switch (op) {
			case 1: { // defmundo
				Consola::clrscr();
				iss >> linhas;
				

				if (linhas < 10) {
					Consola::setTextColor(Consola::VERMELHO_CLARO);
					Consola::gotoxy(45, 35);
					cout << "[ERRO] - Mapa demasiado pequeno!!" << endl;
					Consola::setTextColor(Consola::BRANCO);
					linhas = 0;
					int o = 0;
					break;
				}
				else {
					campo = new Mundo*[linhas];
					for (int i = 0; i <= linhas; i++) {
						campo[i] = new Mundo[linhas];
						for (int j = 0; j <= linhas; j++) {
							//campo[i][j].setOcupante(' ');
							//campo[i][j].setNinho(nullptr);
							//campo[i][j].setFormigas(nullptr);
							//campo[i][j].setComunidade(nullptr);
						}


					}
				}
				flag_dim = 1;
				break;
			}
			case 2: // defen
				//Definir a energia...
				iss >> energia;
				if(ninhos.size() != 0){
					for(auto i = ninhos.begin(); i != ninhos.end(); i++){
						(*i)->setEnergia(energia);
					}
				}
				flag_energia = 1;
				break;


			case 3: // defpc
				break;
			case 4: // defmi
				break;
			case 5: // defme
				break;
			case 6: //defnm
				break;
			case 7:{ // inicio
					if(flag_dim == 0 || flag_energia == 0/* || */){
						Consola::setTextColor(Consola::VERMELHO);
						Consola::gotoxy(2, 13);
						cout << "ERRO!" << endl;
						Consola::setTextColor(Consola::BRANCO);
						cout << "  Não se pode começar a jogar sem: " << endl;
						if(flag_dim == 0)
							cout << "   -Defenir o tamanho do mapa;" << endl;
						if (flag_energia == 0)
							cout << "   -Defenir a energia dos ninhos;" << endl;
					} else {
						ready = 1;
					}
				}
				break;
			case 8: { // executa
				//int linhas, colunas, energia, energia_i, energia_t, pos_miga, energia_miga, max_miga;
					string nomeFicheiro;
					iss >> nomeFicheiro;
					Consola::gotoxy(2, 13);
					cout << "Nome do ficheiro: " << nomeFicheiro << endl;
					string linha;
					ifstream dados(nomeFicheiro);
					if (!dados.is_open())
					{
						Consola::setTextColor(Consola::VERMELHO);
						Consola::gotoxy(2, 14);
						cout << "ERRO!" << endl;
						Consola::setTextColor(Consola::BRANCO);
						cout << "  Nao consegui abrir ficheiro!" << endl;
						break;
					}
					else
					{
						Consola::gotoxy(2, 14);
						cout << "Consegui abrir!" << endl;
					}
					
					// linha 1 (defmundo)
					getline(dados, linha);
					istringstream tam(linha);
					tam >> linhas;
					Consola::gotoxy(2, 17);
					flag_dim = 1;
					cout << "defmundo " << linhas << endl;
					
					// linha 2 (defen)
					getline(dados, linha);
					istringstream mod(linha);
					mod >> energia;
					if (ninhos.size() != 0) {
						for (auto i = ninhos.begin(); i != ninhos.end(); i++) {
							(*i)->setEnergia(energia);
						}
					}
					flag_energia = 1;
					cout << "  defen " << energia << endl;
					
					// linha 3 (defpc)
					getline(dados, linha);
					istringstream moda(linha);
					moda >> energia_i;
					cout << "  defpc " << energia_i << endl;
					
					// linha 4 (defvt)
					getline(dados, linha);
					istringstream modb(linha);
					modb >> energia_t;
					cout << "  defvt " << energia_t << endl;
					
					// linha 5 (defmi)
					getline(dados, linha);
					istringstream modc(linha);
					modc >> pos_miga;
					cout << "  defmi " << pos_miga << endl;
					
					// linha 6 (defme)
					getline(dados, linha);
					istringstream modd(linha);
					modd >> energia_miga;
					cout << "  defme " << energia_miga << endl;
					
					// linha 7 (defnm)
					getline(dados, linha);
					istringstream mode(linha);
					mode >> max_miga;
					cout << "  defnm " << max_miga << endl;	
				}
				break;
			case 9: // limpar
				Consola::clrscr();
				break;
			case 10: // sair
				return 0;
			default:
				Consola::setTextColor(Consola::VERMELHO);
				Consola::gotoxy(2, 13);
				cout << "Comando invalido!" << endl;
				Consola::setTextColor(Consola::BRANCO);
				break;


		}
		
	} while (ready != 1);
	
	while(1){
		ready = 0;
		while(ready != 1){
			margens();
			intro_sim();
			Consola::gotoxy(2, 47);
			cout << "Comando de simulacao: ";
			getline(cin, comando);
			Consola::clrscr();
			istringstream iss(comando);
			iss >> comando;

			op = cmd_sim_op(comando);
			switch(op){

			case 1: // ninho <linha> <coluna>
				break;

			case 2: // criaf <F> <T> <N>
				break;

			case 3: // cria1 <T> <N> <linha> <coluna>
				break;

			case 4: // migalha <linha> <coluna>
				break;

			case 5: // foca <linha> <coluna>
				break;

			case 6: // tempo || tempo <N>
				break;

			case 7: // energninho <N> <E>
				break;

			case 8: // energformiga <linha> <coluna> <E>
				break;

			case 9: // mata <linha> <coluna>
				break;

			case 10: // inseticida <N>
				break;

			case 11: // listamundo
				break;

			case 12: // listaninho <N>
				break;

			case 13: // listaposicao <linha>  <coluna>
				break;

			case 14: // guarda <nome>
				break;

			case 15: // muda <nome>
				break;

			case 16: // apaga <nome>
				break;

			case 17: // sair
				return 0;

			default:
				Consola::setTextColor(Consola::VERMELHO);
				Consola::gotoxy(2, 13);
				cout << "Comando invalido!" << endl;
				Consola::setTextColor(Consola::BRANCO);
				break;
			}
		}
	}

	return 0;

}




