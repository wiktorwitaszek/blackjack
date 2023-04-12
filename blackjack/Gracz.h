#pragma once
#include <iostream>
#include "Karta.h"
//#include "Kasyno.h"

using namespace std;

class Gracz {

	int l_kart = -1 , w_kart = 0;
	 
	Karta* mojekarty[10];
public:
	void wezKarte(Karta* _karta);
	void pokazKarty();
};