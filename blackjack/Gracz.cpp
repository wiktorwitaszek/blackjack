#include "Gracz.h"
#include "Kasyno.h"


Gracz::Gracz(int l, int w, int p){
	l_kart = l;
	w_kart = w;
	pass = p;
}
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

bool Gracz::getPass() {
	return pass;
}
void Gracz::setPass() {
	cout << "Pasujesz? (1 - tak lub 0 - nie)" << endl;
	cin >> pass;
}
void Gracz::setPass(bool p) {
	pass = p;
}

int Gracz::getw_kart() {
	return w_kart;
}