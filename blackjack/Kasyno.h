#pragma once
#include "Karta.h"
#include "Gracz.h"
#include <cstdlib>
#include <vector>
class Kasyno {

	int talia=-1;
	Karta karty[52];
	vector<Gracz> gracze{ Gracz(), Gracz() };

public:
	Kasyno();
	void Przetasuj();
	Karta* dajKarte();
	void graj();
	Gracz winner();
	void playagain();

};
