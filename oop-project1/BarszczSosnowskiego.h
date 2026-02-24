#pragma once
#include "Roœlina.h"

class BarszczSosnowskiego :public Roslina{
public:
	BarszczSosnowskiego(int x, int y);
	void akcja();
	void kolizja(Organizm* drugiOrganizm);
	Organizm* dziecko();
};
