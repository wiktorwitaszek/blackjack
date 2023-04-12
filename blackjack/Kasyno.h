#pragma once
#include "Karta.h"
#include "Gracz.h"
#include <cstdlib>
class Kasyno {

	int talia=-1;
	Karta karty[52];
	Gracz gracze[2];
public:
	Kasyno();
	void Przetasuj();
	Karta* dajKarte();
	void graj();


};
