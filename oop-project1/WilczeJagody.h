#pragma once

#include "Roœlina.h"

class WilczeJagody :public Roslina{
public:
	WilczeJagody(int x, int y);
	void kolizja(Organizm* drugiOrganizm);
	Organizm* dziecko();
};

