#pragma once
#include "Roœlina.h"

class Guarana :	public Roslina{
public:
	Guarana(int x, int y);
	void kolizja(Organizm* drugiOrganizm);
	Organizm* dziecko();
};

