#include "Kasyno.h"

Kasyno::Kasyno() {
	int k=0;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			karty[k].setKolor(j);
			karty[k].setWartosc(i);
			k++;
		}
	}
}




Karta* Kasyno::dajKarte() {
	talia++;
	if (talia >= 52) {
		Przetasuj(); talia = 0;
	}
	
	return &karty[talia];
}

void Kasyno::Przetasuj() {
	int a, b;
	srand(time(nullptr));
	Karta temp;
	for (int i = 0; i < 100; i++)
	{
		a = rand() % 52;
		b = rand() % 52;
		temp = karty[a];
		karty[a] = karty[b];
		karty[b] = temp;
	}
}

void Kasyno::graj() {
	Przetasuj();
	for (int i = 0; i < gracze.size(); i++) {
		cout << "Gracz " << i << endl;
		gracze[i].wezKarte(dajKarte());
		gracze[i].wezKarte(dajKarte());
		
		gracze[i].pokazKarty();
		cout << "-------"<< endl;
	}
	for (int i = 0; i < gracze.size(); i++) {
		do {
		cout << "Gracz " << i << endl;
		gracze[i].setPass();
			if (gracze[i].getPass() == 0) {
				gracze[i].wezKarte(dajKarte());
				gracze[i].pokazKarty();
			}
			
		} while (gracze[i].getPass() == 0);
	}
	winner();
}

Gracz Kasyno::winner() {
	int max_value = gracze[0].getw_kart();
	int max_index = 0;
	for (int i = 1; i < gracze.size(); i++) { //bez & mo¿liwe
		if (gracze[i].getPass() == false) {
			Gracz temp = NULL;
			return temp;
		}
		if (gracze[i].getw_kart() > max_value) {
			max_value = gracze[i].getw_kart();
			max_index = i;
		}
	}
	cout << "Gracz " << max_index << " wygral!" << endl;
	return gracze[max_index];
}

void Kasyno::playagain() {
	for (int i = 0; i < gracze.size(); i++) {
		gracze[i].setPass(0);
	}
	graj();
}