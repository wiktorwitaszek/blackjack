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
	cout << "Blackjack card game\n-------------------\n\n" << "Configure players:\n" << endl;
	if (pa == 0) {
		addPlayer();
		bots[0].setName(1);
		addBots();
	}
	cout << "Starting game..." << endl;
	Sleep(1000);
	system("cls");
	Przetasuj();
	
	for (int i = 0; i < gracze.size(); i++) {
		if (pa == 0) {
			gracze[i].setName();
		}
		gracze[i].wezKarte(dajKarte());
		gracze[i].wezKarte(dajKarte());
		gracze[i].score();
		if (pa == 1)Sleep(300);
	}
	for (int i = 0; i < gracze.size(); i++) {
		do {
			gracze[i].score();
			cout << gracze[i].getName() << ", " ;
		gracze[i].setPass();
			if (gracze[i].getPass() == 0) {
				gracze[i].wezKarte(dajKarte());
				if (gracze[i].getw_kart() > 21) {
					gracze[i].setLose();
					cout << gracze[i].getName() << " went over 21, so he's lost the hand.\n" << endl;
				}
			}
			
		} while (gracze[i].getPass() == 0);
	}


	for (int i = 0; i < bots.size(); i++) {
		if (bots[i].getCourage() == 1) {
			while (bots[i].getw_kart() < 13) {
				bots[i].wezKarte(dajKarte());
				bots[i].score();
				Sleep(300);
			}
		}
		else if (bots[i].getCourage() == 2) {
			while (bots[i].getw_kart() < 15) {
				bots[i].wezKarte(dajKarte());
				bots[i].score();
				Sleep(300);
			}
		}
		else if (bots[i].getCourage() == 3) {
			while (bots[i].getw_kart() < 17) {
				bots[i].wezKarte(dajKarte());
				bots[i].score();
				Sleep(300);
			}
		}
		if (bots[i].getw_kart() > 21) {
			bots[i].setLose();
			cout << bots[i].getName() << " went over 21, so he's lost the hand.\n" << endl;
		}
	}
	winner();
	save();
	playagain();
}

/*Gracz Kasyno::winner() {
	int max_value = 0;
	int max_index = -1;
	int temp = 0;
	do {
		max_index++;
		if (max_index == (gracze.size()+bots.size())) {
			cout << "All players lost!\n" << endl;
			return NULL;
		}
		max_value = gracze[max_index].getw_kart();
	} while (gracze[max_index].getLose() == true && bots[max_index].getLose() == true);
	for (int i = 1; i < gracze.size(); i++) {
		if (gracze[i].getw_kart() > max_value && gracze[i].getLose()==false) {
			max_value = gracze[i].getw_kart();
			max_index = i;
		}
		
		
		
	}//remis
	for (int i = 0; i < gracze.size(); i++) {
		/*
		if (gracze[i].getw_kart() == gracze[i+1].getw_kart()) {
			temp++;
		}
		if (temp == gracze.size() - 1) {

		}
		*//*
		cout << endl << gracze[i].getName() << " score: " << gracze[i].getw_kart() << endl;
	}
	
	cout << endl << gracze[max_index].getName() << " wons!" << endl;
	return gracze[max_index];
}*/

void Kasyno::playagain() {
	char choose = 'n';
	while (1) {
		cout << "Do you want play again?" << endl << "'y' -> yes or 'n' -> no" << endl;
		cin >> choose;
		if (cin.fail() == true || (choose != 'y' && choose != 'n')) {
			cout << "Wrong character selected. Please specify 'y' or 'n'!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			if (choose == 'y') {
				for (int i = 0; i < gracze.size(); i++) {
					gracze[i].reset();
				} 
				for (int i = 0; i < bots.size(); i++) {
					bots[i].reset();
				}
				pa = true;
				graj();
				break; 
			}
			else break;
		}
	}
}
void Kasyno::save() {
	ofstream plik;
	plik.open("score.txt", ofstream::out);
	for (int i = 0; i < gracze.size(); i++) {
		plik << gracze[i].getName() << "  ";
		for (int j = 0; j < gracze[i].getl_kart(); j++) {
			plik << gracze[i].getMojeKarty(j).getKolor() << gracze[i].getMojeKarty(j).getFigura() << "  ";
		}
		
		plik << gracze[i].getw_kart()<< "  "  << endl;
		

	}
	for (int i = 0; i < bots.size(); i++) {
		plik << bots[i].getName() << "  ";
		for (int j = 0; j < bots[i].getl_kart(); j++) {
			plik << bots[i].getMojeKarty(j).getKolor() << bots[i].getMojeKarty(j).getFigura() << "  ";
		}

		plik << bots[i].getw_kart() << "  " << endl;


	}
	plik.close();

}

void Kasyno::addPlayer(){
	char choose = 'n';
	cout << gracze.size() << " players in game." << endl;
	while (1) {
		cout << "Do you want to add a player?" << endl << "'y' -> yes or 'n' -> no" << endl;
		cin >> choose;
		if (std::cin.fail() == true || (choose != 'y' && choose != 'n')) {
			std::cout << "Wrong character selected. Please specify 'y' or 'n'!" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else {
			
			switch (choose) {
			case 'y':
				gracze.push_back(Gracz(this));
				cout << gracze.size() << " players in game." << endl;
				if (gracze.size() >= 3)
				{
					cout <<"3 players is the maximum\n" << endl;
					return;
				}
				break;
			case 'n':
				return;

			}
		}
	}
}
void Kasyno::addBots() {
	cout << bots[0].getName() << endl;
	bots[0].setCourage();
	char choose = 'n';
	cout << bots.size() << " bots in game." << endl;
	while (1) {
		cout << "Do you want to add a bot?" << endl << "'y' -> yes or 'n' -> no" << endl;
		cin >> choose;
		if (std::cin.fail() == true || (choose != 'y' && choose != 'n')) {
			std::cout << "Wrong character selected. Please specify 'y' or 'n'!" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else {
			int i = bots.size();
			switch (choose) {
			case 'y':
				bots.push_back(Bot(this));
				cout << bots.size() << " bots in game." << endl;
				bots[i].setName(i+1);
				cout << bots[i].getName() << endl;
				bots[i].setCourage();
				if (bots.size() >= 3)
				{
					cout << "3 bots is the maximum\n" << endl;
					return;
				}
				break;
			case 'n':
				return;

			}
		}
	}
}
void Kasyno::winner() {
	Gracz* najlepszyGracz = nullptr;
	int max_value = 0;

	for (int i = 0; i < gracze.size(); i++) {
		if (gracze[i].getw_kart() > max_value && gracze[i].getLose() == false) {
			najlepszyGracz = &gracze[i];
			max_value = gracze[i].getw_kart();
		}
	}

	for (int i = 0; i < bots.size(); i++) {
		if (bots[i].getw_kart() > max_value && bots[i].getLose() == false) {
			najlepszyGracz = &bots[i];
			max_value = bots[i].getw_kart();
		}
	}
	for (int i = 0; i < gracze.size(); i++) {
		/*
		if (gracze[i].getw_kart() == gracze[i+1].getw_kart()) {
			temp++;
		}
		if (temp == gracze.size() - 1) {

		}
		*/
		cout << endl << gracze[i].getName() << " score: " << gracze[i].getw_kart() << endl;
	}
	for (int i = 0; i < bots.size(); i++) {
	
		cout << endl << bots[i].getName() << " score: " << bots[i].getw_kart() << endl;
	}

	cout << endl << najlepszyGracz->getName() << " wons!" << endl;
}