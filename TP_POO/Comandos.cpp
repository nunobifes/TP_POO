#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <fstream>

#include "Gestor.h"
#include "Screen.h"
#include "Consola.h"
#include "Mundo.h"

using namespace std;

int flagEnerg = 0, flagTam = 0, flagPerc = 0, flagMEnerg = 0, flagMPerc = 0, flagMMax = 0;
char t;
int op, linhas = 0, energia = 0, energia_perc = 0, energia_transf = 0, per_miga = 0, energia_miga = 0, max_miga = 0, linha= 0, coluna= 0, n=0, f = 0, vezes = 0;
string nome, comando;



bool Comandos::menu_config(Mundo* m, Screen* s)const {

	// "Menu" inicial de configura��o 
	

	Consola::gotoxy(2, 47);
	cout << "Comando de configuracao: ";
	getline(cin, comando);
	Consola::clrscr();
	istringstream iss(comando);
	iss >> comando;

	op = s->cmd_op(comando);
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

		m->setLim(linhas);
		flagTam = 1;
		Consola::setTextColor(Consola::VERDE);
		Consola::gotoxy(2, 13);
		cout << "Tamanho definido para para o mapa: ";
		Consola::setTextColor(Consola::AZUL_CLARO);
		cout << linhas << 'x' << linhas << endl;
		Consola::setTextColor(Consola::BRANCO);
		break;
	}
	case 2: // defen
			//Definir a energia...
		iss >> energia;
		m->set_energ_ninho(energia);
		flagEnerg = 1;

		Consola::setTextColor(Consola::VERDE);
		Consola::gotoxy(2, 13);
		cout << "Energia definida para cada ninho: ";
		Consola::setTextColor(Consola::AZUL_CLARO);
		cout << energia << endl;
		Consola::setTextColor(Consola::BRANCO);

		break;


	case 3: // defpc
		iss >> energia_perc;
		m->set_perc_energ(energia_perc);
		flagPerc = 1;

		Consola::setTextColor(Consola::VERDE);
		Consola::gotoxy(2, 13);
		cout << "Percentagem definida para cria��o de uma formiga: ";
		Consola::setTextColor(Consola::AZUL_CLARO);
		cout << energia_perc << '%' << endl;
		Consola::setTextColor(Consola::BRANCO);
		break;
	case 4: // defvt
		iss >> energia_transf;
		m->set_energ_transf(energia_transf);

		Consola::setTextColor(Consola::VERDE);
		Consola::gotoxy(2, 13);
		cout << "Energia transferida por itera��o: ";
		Consola::setTextColor(Consola::AZUL_CLARO);
		cout << energia_transf << endl;
		Consola::setTextColor(Consola::BRANCO);
		break;
	case 5: // defmi
		iss >> per_miga;
		m->set_m_per_inicial(per_miga);
		flagMPerc = 1;

		Consola::setTextColor(Consola::VERDE);
		Consola::gotoxy(2, 13);
		cout << "Percentagem de migalhas definida para o mundo: ";
		Consola::setTextColor(Consola::AZUL_CLARO);
		cout << per_miga << '%' << endl;
		Consola::setTextColor(Consola::BRANCO);
		break;
	case 6: // defme
		iss >> energia_miga;
		m->set_m_e_inical(energia_miga);
		flagMEnerg = 1;

		Consola::setTextColor(Consola::VERDE);
		Consola::gotoxy(2, 13);
		cout << "Energia definida para cada migalha: ";
		Consola::setTextColor(Consola::AZUL_CLARO);
		cout << energia_miga << endl;
		Consola::setTextColor(Consola::BRANCO);
		break;
	case 7: //defnm
		iss >> max_miga;
		m->set_m_max(max_miga);
		flagMMax = 1;

		Consola::setTextColor(Consola::VERDE);
		Consola::gotoxy(2, 13);
		cout << "Numero maximo de migalhas definido para o mundo: ";
		Consola::setTextColor(Consola::AZUL_CLARO);
		cout << max_miga << endl;
		Consola::setTextColor(Consola::BRANCO);
		break;
	case 8: { // inicio
		if (flagTam == 0 || flagEnerg == 0 || flagPerc == 0 || flagMEnerg == 0 || flagMPerc == 0 || flagMMax == 0) {
			Consola::setTextColor(Consola::VERMELHO);
			Consola::gotoxy(2, 13);
			cout << "ERRO!" << endl;
			Consola::setTextColor(Consola::BRANCO);
			cout << "  N�o se pode come�ar a jogar sem: " << endl;
			if (flagTam == 0)
				cout << "   -Defenir o tamanho do mapa;" << endl;
			if (flagEnerg == 0)
				cout << "   -Defenir a energia dos ninhos;" << endl;
			if (flagPerc == 0)
				cout << "   -Defenir a percentagem de enrgia para criar nova formiga;" << endl;
			if (flagMEnerg == 0)
				cout << "   -Defenir a energia das migalhas;" << endl;
			if (flagMPerc == 0)
				cout << "   -Defenir a percentagem de migalhas iniciais a existir;" << endl;
			if (flagMMax == 0)
				cout << "   -Defenir a o numero maximo de migalhas a serem criadas por iteracao;" << endl;
		}
		else {
			return true;
		}
	}
			break;
	case 9: { // executa
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
		m->setLim(linhas);
		Consola::gotoxy(2, 17);
		flagTam = 1;
		cout << "defmundo " << linhas << endl;

		// linha 2 (defen)
		getline(dados, linha);
		istringstream mod(linha);
		mod >> energia;
		m->set_energ_ninho(energia);
		flagEnerg = 1;
		cout << "  defen " << energia << endl;

		// linha 3 (defpc)
		getline(dados, linha);
		istringstream moda(linha);
		moda >> energia_perc;
		m->set_perc_energ(energia_perc);
		cout << "  defpc " << energia_perc << endl;
		flagPerc = 1;

		// linha 4 (defvt)
		getline(dados, linha);
		istringstream modb(linha);
		modb >> energia_transf;
		m->set_energ_transf(energia_transf);
		cout << "  defvt " << energia_transf << endl;
		
		// linha 5 (defmi)
		getline(dados, linha);
		istringstream modc(linha);
		modc >> per_miga;
		m->set_m_per_inicial(per_miga);
		cout << "  defmi " << per_miga << endl;
		flagMPerc = 1;

		// linha 6 (defme)
		getline(dados, linha);
		istringstream modd(linha);
		modd >> energia_miga;
		m->set_m_e_inical(energia_miga);
		cout << "  defme " << energia_miga << endl;
		flagMEnerg = 1;

		// linha 7 (defnm)
		getline(dados, linha);
		istringstream mode(linha);
		mode >> max_miga;
		m->set_m_max(max_miga);
		cout << "  defnm " << max_miga << endl;
		flagMMax = 1;
	}
			break;
	case 10: // limpar
		Consola::clrscr();
		break;
	case 11: // sair
		exit(EXIT_SUCCESS);
	default:
		Consola::setTextColor(Consola::VERMELHO);
		Consola::gotoxy(2, 13);
		cout << "[ERRO] - Comando invalido!" << endl;
		Consola::setTextColor(Consola::BRANCO);
		break;


	}
	return false;
}

bool Comandos::menu_simul(vector <Mundo*> *saves, Mundo** ppm, Screen* s)const {
	Mundo * m = *ppm;
	Consola::gotoxy(2, 47);
	cout << "Comando de simulacao: ";
	getline(cin, comando);
	Consola::clrscr();
	istringstream iss(comando);
	iss >> comando;

	op = s->cmd_sim_op(comando);
	switch (op) {

	case 1: // ninho <linha> <coluna>
		iss >> linha;
		iss >> coluna;
		if (m->get_comunidade().size() > 9){
			Consola::setTextColor(Consola::VERMELHO);
			Consola::gotoxy(2, 13);
			cout << "[ERRO] - Tamanho maximo de Comunidades atingido!" << endl;
			Consola::setTextColor(Consola::BRANCO);
			break;
		}
		if (linha < m->get_lim() && coluna < m->get_lim()) {
			int x = 0, y = 0;
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == linha)
					y = i;
			}
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == coluna)
					x = i;
			}
			m->set_ninho_xy(x, y);
			m->cria_comunidade();
		}else
		{
			Consola::setTextColor(Consola::VERMELHO_CLARO);
			Consola::gotoxy(45, 40);
			cout << "Posi��o ultrapassa tamanho do mundo!" << endl;
			Consola::setTextColor(Consola::BRANCO);
		}
		break;

	case 2: // criaf <F> <T> <N>
		iss >> f;
		iss >> t;
		iss >> n;
		
			for (auto i = 0; i < m->get_comunidade().size(); i++)
			{
				Comunidade *comu = m->get_comunidade().at(i);
				if (comu->get_id() == n)
				{
					for(auto j = 0; j < f; j++)
						comu->add_formiga(m->get_lim(), t, -1, -1);
				}

			}

		break;

	case 3: // cria1 <T> <N> <linha> <coluna>
		iss >> t;
		iss >> n;
		iss >> linha;
		iss >> coluna;
		if (linha < m->get_lim() && coluna < m->get_lim()) {
			int x = 0, y = 0;
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == linha)
					y = i;
			}
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == coluna)
					x = i;
			}
			for(auto i = 0; i < m->get_comunidade().size(); i++)
			{
				Comunidade *comu = m->get_comunidade().at(i);
				if (comu->get_id() == n )
				{
					comu->add_formiga(m->get_lim(), t, x, y);
				}
				
			}
		}
		else
		{
			Consola::setTextColor(Consola::VERMELHO_CLARO);
			Consola::gotoxy(45, 40);
			cout << "Posi��o ultrapassa tamanho do mundo!" << endl;
			Consola::setTextColor(Consola::BRANCO);
		}
		break;

	case 4: // migalha <linha> <coluna>
		iss >> linha;
		iss >> coluna;
		if (linha < m->get_lim() && coluna < m->get_lim()) {
			int x = 0, y = 0;
			for (auto i = 0; i < m->get_lim(); i++) {
				if (i == linha)
					y = i;
			}
			for (auto i = 0; i < m->get_lim(); i++) {
				if (i == coluna)
					x = i;
			}
			m->cria_migalha(x, y);
		}
		else
		{
			Consola::setTextColor(Consola::VERMELHO_CLARO);
			Consola::gotoxy(45, 40);
			cout << "Posi��o ultrapassa tamanho do mundo!" << endl;
			Consola::setTextColor(Consola::BRANCO);
		}
		
		break;

	case 5: // foca <linha> <coluna>
		break;

	case 6: // tempo || tempo <N>
		iss >> vezes;
		m->avanca_tempo(vezes);
		break;

	case 7: // energninho <N> <E>
		
		iss >> n;
		iss >> energia;
		m->add_energia_ninho(n, energia);

		break;

	case 8: // energformiga <linha> <coluna> <E>
		iss >> linha;
		iss >> coluna;
		iss >> energia;
		if (linha < m->get_lim() && coluna < m->get_lim()) {
			int x = 0, y = 0;
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == linha)
					y = i;
			}
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == coluna)
					x = i;
			}

			m->add_energia_formiga(x, y, energia);
		}
		break;

	case 9: // mata <linha> <coluna>
		iss >> linha;
		iss >> coluna;
		
		if (linha < m->get_lim() && coluna < m->get_lim()) {
			int x = 0, y = 0;
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == linha)
					y = i;
			}
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == coluna)
					x = i;
			}

			for (auto i = 0; i < m->get_comunidade().size(); i++)
				m->get_comunidade().at(i)->mata_formiga(x, y);
		}
		else
		{
			Consola::setTextColor(Consola::VERMELHO_CLARO);
			Consola::gotoxy(45, 40);
			cout << "Posicao ultrapassa tamanho do mundo!" << endl;
			Consola::setTextColor(Consola::BRANCO);
		}
		break;
	case 10:	// ninho entrar em guerra
		iss >> n;

		m->modo_guerra(true, n);
		break;

	case 11:	// ninho entrar em paz
		iss >> n;

		m->modo_guerra(false, n);
		break;

	case 12:	// gerir formigas Soldado
		break;

	case 13: // inseticida <N>

		iss >> n;

		m->elimina_comunidade(n);

		break;

	case 14: // listamundo
		s->lista_mundo(ppm);
		break;

	case 15: // listaninho <N>
		iss >> n;
		s->lista_ninho(ppm, n);
		break;

	case 16: // listaposicao <linha>  <coluna>
		iss >> linha;
		iss >> coluna;
		if (linha < m->get_lim() && coluna < m->get_lim()) {
			int x = 0, y = 0;
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == linha)
					y = i;
			}
			for (auto i = 0; i <= m->get_lim(); i++) {
				if (i == coluna)
					x = i;
			}
			s->lista_posicao(ppm, x, y);
		}
		else
		{
			Consola::setTextColor(Consola::VERMELHO_CLARO);
			Consola::gotoxy(45, 40);
			cout << "Posicao ultrapassa tamanho do mundo!" << endl;
			Consola::setTextColor(Consola::BRANCO);
		}
		
		break;

	case 17: { // guarda <nome>		\\ Nada funciona
		iss >> nome;
		auto *sav = new Mundo(*m);
		sav->set_nome(nome);
		saves->push_back(sav);
	}
		break;

	case 18: // muda <nome>
		iss >> nome;
		for(auto i = 0; i < saves->size(); i++)
		{
			if(saves->at(i)->get_nome() == nome)
			{
				delete m;

				*ppm = new Mundo(*saves->at(i));
				m = *ppm;
			}
			else
			{
				Consola::setTextColor(Consola::VERMELHO_CLARO);
				Consola::gotoxy(45, 40);
				cout << "Esse Mundo n�o existe!" << endl;
				Consola::setTextColor(Consola::BRANCO);
			}
		}
		Consola::clrscr();
		break;

	case 19: // apaga <nome>
		iss >> nome;
		for (auto i = 0; i < saves->size(); i++)
			if (saves->at(i)->get_nome() == nome)
			{
				saves->erase(saves->begin() + i);
			}
				
		break;


	case 20: // sair
		
		Comunidade::reset_id();
		//m->get_comunidade().at((m->get_comunidade().size() - 1))->reset_id();
		delete m;
		*ppm = new Mundo(10, 1);
		m = *ppm; // para o caso de usar m daqui a bocado nesta fun��o
		flagEnerg = 0, flagTam = 0, flagPerc = 0, flagMEnerg = 0, flagMPerc = 0, flagMMax = 0;
		linhas = 0, energia = 0, energia_perc = 0, energia_transf = 0, per_miga = 0, energia_miga = 0, max_miga = 0, linha = 0, coluna = 0, n = 0, f = 0, vezes = 0;
		return true;

	default:
		Consola::setTextColor(Consola::VERMELHO);
		Consola::gotoxy(2, 13);
		cout << "[ERRO] - Comando invalido!" << endl;
		Consola::setTextColor(Consola::BRANCO);
		break;
	}
	return false;
}