#include "Gracz.h"


Gracz::Gracz(Kasyno* _k,int l, int w, bool p, bool lo, string n){
	l_kart = l;
	w_kart = w;
	pass = p;
	lose = lo;
	name = n;
	k = _k;
}
void Gracz::wezKarte(Karta* _karta) {
	l_kart++;
	if (l_kart < 10) { 
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
Karta Gracz::getMojeKarty(int l) {
	return *mojekarty[l];
}

bool Gracz::getPass() {
	return pass;
}
void Gracz::setPass() {
	char choose = 'n';
	while (1) {
		cout << "Picking a card?" << endl << "'y' -> yes or 'n' -> no" << endl;
		cin >> choose;
		if (cin.fail() == true || (choose != 'y' && choose != 'n')) {
			cout << "Wrong character selected. Please specify 'y' or 'n'!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			if (choose == 'y') pass = 0;
			else {
				pass = 1;
			}
			break;
		}
	}
}
void Gracz::setPass(bool p) {
	pass = p;
}

int Gracz::getw_kart() {
	return w_kart;
}
int Gracz::getl_kart() {
	return l_kart;
}
string Gracz::getName() {
	return name;
}
void Gracz::setName() {
	cout << "Enter the name of the player: ";
	cin >> name;
}
void Gracz::setLose() {
	lose = true;
	pass = true;
}

bool Gracz::getLose() {
	return lose;
}
void Gracz::reset() {
	w_kart = -1;
	pass = false;
	lose = false;
	for (int i = 0; i < l_kart; i++) {
		mojekarty[i] = nullptr;
	}
	l_kart = -1;
}
void Gracz::score() {
	cout << getName() << endl;
	cout << "-------" << endl;
	pokazKarty();
	cout << "\n-------" << endl;
	cout << "score: " << getw_kart() << endl;
	cout << "-----------" << endl;
}