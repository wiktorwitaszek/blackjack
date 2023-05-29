#pragma once
#include "Gracz.h"
#include "string"
class Bot : public Gracz {
	int courage;
public:
	Bot(Kasyno* _k,string = "Bot");
	void setCourage(); 
	void setName(int);
	string getName();
	void setPass();
	int getCourage();
};
