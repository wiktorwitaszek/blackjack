#pragma once
#include "Karta.h"
#include "Gracz.h"
#include "Bot.h"
#include <cstdlib>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

class Kasyno {

	int talia=-1;
	bool pa = false;
	Karta karty[52];
	vector<Gracz> gracze{ Gracz(this)};
	vector<Bot> bots{ Bot(this) };

public:
	Kasyno();
	void Przetasuj();
	Karta* dajKarte();
	void graj();
	void winner();
	void playagain();
	void save();
	void addPlayer();
	void addBots();

};
