#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>


#include "Screen.h"
#include "Consola.h"
#include "Mundo.h"
#include "Gestor.h"

int Screen::cmd_op(string s) {
	int op = 0;
	if (!s.compare("defmundo"))
		op = 1;
	else if (!s.compare("defen"))		
		op = 2;
	else if (!s.compare("defpc"))
		op = 3;
	else if (!s.compare("defpc"))
		op = 4;
	else if (!s.compare("defmi"))
		op = 5;
	else if (!s.compare("defme"))
		op = 6;
	else if (!s.compare("defnm"))
		op = 7;
	else if (!s.compare("inicio"))
		op = 8;
	else if (!s.compare("executa"))
		op = 9;
	else if (!s.compare("limpar"))
		op = 10;
	else if (!s.compare("sair"))
		op = 11;
	return op;
}

int Screen::cmd_sim_op(string s) {
	int op = 0;
	if (!s.compare("ninho"))
		op = 1;
	else if (!s.compare("criaf"))			//funciona como o introduzir o numero de moedas no tp ano passado
		op = 2;
	else if (!s.compare("cria1"))
		op = 3;
	else if (!s.compare("migalha"))
		op = 4;
	else if (!s.compare("foca"))
		op = 5;
	else if (!s.compare("tempo"))
		op = 6;
	else if (!s.compare("energninho"))
		op = 7;
	else if (!s.compare("energformiga"))
		op = 8;
	else if (!s.compare("mata"))
		op = 9;
	else if (!s.compare("inseticida"))
		op = 10;
	else if (!s.compare("listamundo"))
		op = 11;
	else if (!s.compare("listaninho"))
		op = 12;
	else if (!s.compare("listaposicao"))
		op = 13;
	else if (!s.compare("guarda"))
		op = 14;
	else if (!s.compare("muda"))
		op = 15;
	else if (!s.compare("apaga"))
		op = 16;
	else if (!s.compare("sair"))
		op = 17;
	return op;
}

void Screen::mostra_mapa() {

	//Consola::clrscr();

	for (int y = 17; y < 39; y++) {
		for (int x = 58; x < 80; x++) {
			Consola::gotoxy(x, y);
			if (x == 58 || y == 17 || x == 79 || y == 38)
			{

				Consola::setBackgroundColor(Consola::BRANCO_CLARO);
				cout << (char)219;
			}

			else
			{
				Consola::setBackgroundColor(Consola::VERDE_CLARO);
				cout << ' ';
			}
		}
	}
	Consola::setBackgroundColor(Consola::PRETO);


}

void Screen::desenha(Mundo* m)
{	
	
	if (m->get_comunidade().size() != 0)
	{
		int xn, yn, xf, yf;
		Consola::setBackgroundColor(Consola::VERDE_CLARO);
		for (auto i = 0; i < m->get_comunidade().size(); i++)
		{
			// NINHOS
			Comunidade *comu = m->get_comunidade().at(i);
			xn = comu->get_ninho()->getPosX();
			yn = comu->get_ninho()->getPosY();
			if (xn > 58 && xn < 80 && yn > 17 && yn < 39) {
				Consola::gotoxy(xn, yn);
				Consola::setTextColor(Consola::AZUL);
				cout << "N";
				Consola::setTextColor(Consola::BRANCO);
			}

			//FORMIGAS
			for(auto j = 0; j < comu->get_formiga().size(); j++)
			{
				Formiga* form = comu->get_formiga().at(j);
				xf = form->get_posX();
				yf = form->get_posY();
				if (xf > 58 && xf < 80 && yf > 17 && yf < 39) {
					Consola::gotoxy(xf, yf);
					
					Consola::setTextColor(form->get_cor());
					cout << 'f';
					Consola::setTextColor(Consola::BRANCO);
				}
			}
		}
	}

	int x, y;
	Consola::setBackgroundColor(Consola::VERDE_CLARO);
	for(auto i = 0; i < m->get_migalha().size(); i++)
	{
		Migalha* migalha = m->get_migalha().at(i);
		x = migalha->get_posx();
		y = migalha->get_posy();
		if (x > 58 && x < 80 && y > 17 && y < 39) {
			Consola::gotoxy(x, y);
			Consola::setTextColor(Consola::AMARELO);
			cout << "*";
			Consola::setTextColor(Consola::BRANCO);
		}
	}
	Consola::setBackgroundColor(Consola::PRETO);
}


void Screen::margens() {

	Consola::setTextColor(Consola::VERMELHO);
	Consola::gotoxy(22, 2); cout << "      :::::::::: ::::::::  :::::::::    :::   :::   ::::::::::: ::::::::      :::      :::::::: ";
	Consola::gotoxy(22, 3); cout << "     :+:       :+:    :+: :+:    :+:  :+:+: :+:+:      :+:    :+:    :+:   :+: :+:   :+:    :+: ";
	Consola::gotoxy(22, 4); cout << "    +:+       +:+    +:+ +:+    +:+ +:+ +:+:+ +:+     +:+    +:+         +:+   +:+  +:+         ";
	Consola::gotoxy(22, 5); cout << "   :#::+::#  +#+    +:+ +#++:++#:  +#+  +:+  +#+     +#+    :#:        +#++:++#++: +#++:++#++   ";
	Consola::gotoxy(22, 6); cout << "  +#+       +#+    +#+ +#+    +#+ +#+       +#+     +#+    +#+   +#+# +#+     +#+        +#+    ";
	Consola::gotoxy(22, 7); cout << " #+#       #+#    #+# #+#    #+# #+#       #+#     #+#    #+#    #+# #+#     #+# #+#    #+#     ";
	Consola::gotoxy(22, 8); cout << "###        ########  ###    ### ###       ### ########### ########  ###     ###  ########       ";


	Consola::setTextColor(Consola::CINZENTO);
	for (int a = 0; a < 140; a++) {
		Consola::gotoxy(a, 0);
		cout << (char)219;
		Consola::gotoxy(a, 48);
		cout << (char)220;
	}
	for (int a = 1; a < 49; a++) {
		Consola::gotoxy(0, a);
		cout << (char)219;
		Consola::gotoxy(139, a);
		cout << (char)219;
	}
	Consola::setTextColor(Consola::BRANCO);

};



void Screen::intro() {
	
	for (int a = 1; a < 139; a++) {
		Consola::setTextColor(Consola::CINZENTO);
		Consola::gotoxy(a, 10);
		cout << (char)219;
	}
	Consola::setTextColor(Consola::BRANCO);
	Consola::gotoxy(120, 26);	cout << "comandos: ";
	Consola::gotoxy(120, 27);	cout << " -defmundo";
	Consola::gotoxy(120, 28);	cout << " -defen ";
	Consola::gotoxy(120, 29);	cout << " -defpc";
	Consola::gotoxy(120, 30);	cout << " -defvt";
	Consola::gotoxy(120, 31);	cout << " -defmi";
	Consola::gotoxy(120, 32);	cout << " -defme";
	Consola::gotoxy(120, 33);	cout << " -defnm";
	Consola::gotoxy(120, 34);	cout << " -inicio";
	Consola::gotoxy(120, 35);	cout << " -executa";
	Consola::gotoxy(120, 36);	cout << " -limpar";
	Consola::gotoxy(120, 37);	cout << " -sair";


	Consola::setTextColor(Consola::BRANCO);
	for (int a = 118; a < 136; a++) {
		Consola::gotoxy(a, 25);
		cout << (char)205;
		Consola::gotoxy(a, 38);
		cout << (char)205;
	}
	for (int a = 26; a < 38; a++) {
		Consola::gotoxy(118, a);
		cout << (char)186;
		Consola::gotoxy(135, a);
		cout << (char)186;
	}

	Consola::gotoxy(118, 25);
	cout << (char)201;
	Consola::gotoxy(135, 25);
	cout << (char)187;
	Consola::gotoxy(118, 38);
	cout << (char)200;
	Consola::gotoxy(135, 38);
	cout << (char)188;

};

void Screen::intro_sim() {
	
	for (int a = 1; a < 139; a++) {
		Consola::setTextColor(Consola::CINZENTO);
		Consola::gotoxy(a, 10);
		cout << (char)219;
	}
	Consola::setTextColor(Consola::BRANCO);
	Consola::gotoxy(120, 26);	cout << "comandos: ";
	Consola::gotoxy(120, 27);	cout << " -ninho";
	Consola::gotoxy(120, 28);	cout << " -criaf";
	Consola::gotoxy(120, 29);	cout << " -cria1";
	Consola::gotoxy(120, 30);	cout << " -migalha";
	Consola::gotoxy(120, 31);	cout << " -foca";
	Consola::gotoxy(120, 32);	cout << " -tempo";
	Consola::gotoxy(120, 33);	cout << " -energninho";
	Consola::gotoxy(120, 34);	cout << " -energformiga";
	Consola::gotoxy(120, 35);	cout << " -mata";
	Consola::gotoxy(120, 36);	cout << " -inseticida";
	Consola::gotoxy(120, 37);	cout << " -listamundo";
	Consola::gotoxy(120, 38);	cout << " -listaninho";
	Consola::gotoxy(120, 39);	cout << " -listaposicao";
	Consola::gotoxy(120, 40);	cout << " -guarda";
	Consola::gotoxy(120, 41);	cout << " -muda";
	Consola::gotoxy(120, 42);	cout << " -apaga";
	Consola::gotoxy(120, 43);	cout << " -sair";


	Consola::setTextColor(Consola::BRANCO);
	for (int a = 118; a < 136; a++) {
		Consola::gotoxy(a, 25);
		cout << (char)205;
		Consola::gotoxy(a, 44);
		cout << (char)205;
	}
	for (int a = 26; a < 44; a++) {
		Consola::gotoxy(118, a);
		cout << (char)186;
		Consola::gotoxy(135, a);
		cout << (char)186;
	}

	Consola::gotoxy(118, 25);
	cout << (char)201;
	Consola::gotoxy(135, 25);
	cout << (char)187;
	Consola::gotoxy(118, 44);
	cout << (char)200;
	Consola::gotoxy(135, 44);
	cout << (char)188;



};