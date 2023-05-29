#pragma once
#include <iostream>
#include "Karta.h"

using namespace std;
class Kasyno;

class Gracz {
protected:
	int l_kart, w_kart;
	bool pass, lose;
	string name;
	Kasyno* k;
	Karta* mojekarty[10];
public:
	Gracz(Kasyno* _k, int = -1, int = -1, bool = false, bool = false, string = "Player");
	void wezKarte(Karta* _karta);
	Karta getMojeKarty(int);
	void pokazKarty();
	void setPass();
	void setPass(bool);
	bool getPass();
	int getw_kart();
	int getl_kart();
	string getName();
	void setName();
	void setLose();
	bool getLose();
	void reset();
	void score();
};