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
	gracze[0].wezKarte(dajKarte());
	gracze[0].wezKarte(dajKarte());
	gracze[1].wezKarte(dajKarte());
	gracze[1].wezKarte(dajKarte());
	gracze[0].pokazKarty();
	gracze[1].pokazKarty();

}