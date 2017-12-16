﻿#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>


#include "Screen.h"
#include "Consola.h"
#include "Mundo.h"

int cmd_op(string s) {
	int op = 0;
	if (!s.compare("defmundo"))
		op = 1;
	else if (!s.compare("defen"))			//funciona como o introduzir o numero de moedas no tp ano passado
		op = 2;
	else if (!s.compare("defpc"))
		op = 3;
	else if (!s.compare("defmi"))
		op = 4;
	else if (!s.compare("defme"))
		op = 5;
	else if (!s.compare("defnm"))
		op = 6;
	else if (!s.compare("inicio"))
		op = 7;
	else if (!s.compare("executa"))
		op = 8;
	else if (!s.compare("muda"))
		op = 9;
	else if (!s.compare("apaga"))
		op = 10;
	else if (!s.compare("sair"))
		op = 11;
	return op;
}

void mostra_mapa(int linha, int coluna, Mundo **campo) {

	Consola::clrscr();

	for (int y = 10; y < 30; y++) {
		for (int x = 40; x < 100; x++) {
			Consola::gotoxy(x, y);
			if (x == 40 || y == 10 || x == 99 || y == 29)
			{

				Consola::setBackgroundColor(Consola::BRANCO_CLARO);
				cout << (char)219;
			}

			else
			{
				Consola::setBackgroundColor(Consola::VERMELHO_CLARO);
				cout << ' ';
			}
		}
	}
	Consola::setBackgroundColor(Consola::PRETO);





}
void margens() {
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



void intro() {
	Consola::setTextColor(Consola::VERDE);
	Consola::gotoxy(22, 2); cout << "      :::::::::: ::::::::  :::::::::    :::   :::   ::::::::::: ::::::::      :::      :::::::: ";
	Consola::gotoxy(22, 3); cout << "     :+:       :+:    :+: :+:    :+:  :+:+: :+:+:      :+:    :+:    :+:   :+: :+:   :+:    :+: ";
	Consola::setTextColor(Consola::AMARELO);
	Consola::gotoxy(22, 4); cout << "    +:+       +:+    +:+ +:+    +:+ +:+ +:+:+ +:+     +:+    +:+         +:+   +:+  +:+         ";
	Consola::gotoxy(22, 5); cout << "   :#::+::#  +#+    +:+ +#++:++#:  +#+  +:+  +#+     +#+    :#:        +#++:++#++: +#++:++#++   ";
	Consola::setTextColor(Consola::AZUL);
	Consola::gotoxy(22, 6); cout << "  +#+       +#+    +#+ +#+    +#+ +#+       +#+     +#+    +#+   +#+# +#+     +#+        +#+    ";
	Consola::gotoxy(22, 7); cout << " #+#       #+#    #+# #+#    #+# #+#       #+#     #+#    #+#    #+# #+#     #+# #+#    #+#     ";
	Consola::setTextColor(Consola::VERMELHO);
	Consola::gotoxy(22, 8); cout << "###        ########  ###    ### ###       ### ########### ########  ###     ###  ########       ";
	
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
	Consola::gotoxy(120, 30);	cout << " -defmi";
	Consola::gotoxy(120, 31);	cout << " -defme";
	Consola::gotoxy(120, 32);	cout << " -defnm";
	Consola::gotoxy(120, 33);	cout << " -inicio";
	Consola::gotoxy(120, 34);	cout << " -executa";
	Consola::gotoxy(120, 35);	cout << " -muda";
	Consola::gotoxy(120, 36);	cout << " -apaga";
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