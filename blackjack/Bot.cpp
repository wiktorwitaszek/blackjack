#include "Bot.h"

Bot::Bot(Kasyno* _k, string n) : Gracz(_k){
	name = n;
}
void Bot::setCourage() {
	int c =0;

	while (1) {
		cout << "Set the courage:" << endl;
		cout << "1 - conservative\n2 - normal\n3 - risky" << endl;
		cin >> c;
		if (cin.fail() == true || (c != 1 && c != 2 && c != 3)) {
			cout << "Wrong character selected. Please specify 1, 2 or 3!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else {
			if (c == 1) courage = 1;
			else if (c == 2) courage = 2;
			else if (c == 3) courage = 3;
				break;
			}
		}
	}


void Bot::setName(int i) {
	string iStr = to_string(i);
	name += iStr;
}
string Bot::getName() {
	return name;
}

void Bot::setPass() {
	;
}
int Bot::getCourage() {
	return courage;
}