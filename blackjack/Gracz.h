#pragma once
#include <iostream>
#include "Karta.h"


using namespace std;

class Gracz {

	int l_kart, w_kart;
	bool pass;
	 
	Karta* mojekarty[10];
public:
	Gracz(int = -1, int = -1, int = 0);
	void wezKarte(Karta* _karta);
	void pokazKarty();
	void setPass();
	void setPass(bool);
	bool getPass();
	int getw_kart();
};