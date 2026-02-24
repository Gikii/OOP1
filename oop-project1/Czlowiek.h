#pragma once
#include "Zwierze.h"


class Czlowiek : public Zwierze{
private:
	int umiejetnosc;
	pair<int, int> kierunek;
	const int sasiedzi[8][2] = { {-1,-1},{-1,0},{0,-1},{1,0},{0,1},{1,1},{1,-1},{-1,1} };
public:
	Czlowiek(int x, int y);
	void akcja();
	bool ustawKierunek(pair<int, int> kierunek);
	void aktywujUmiejetnosc();
	void ustawCooldownUmiejetnosci(int umiejetnosc);
	string getInformacje();
	Czlowiek* dziecko();
};

