#include "Gracz.h"

void Gracz::wezKarte(Karta* _karta) {
	l_kart++;
	if (l_kart < 10) { 
		//mojekarty = new Karta[l_kart];
		mojekarty[l_kart] = _karta;
		w_kart += _karta->getWartosc();
	}
	else {
		l_kart--;
	}
}

void Gracz::pokazKarty() {
	for (int i = 0; i <= l_kart; i++) {
		mojekarty[i]->wypisz();
	}
}
