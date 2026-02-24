#pragma once
#include "Organizm.h"


class Roslina :	public Organizm {
public:
	Roslina(char znak, int sila, int x, int y);
	virtual void akcja();
	virtual void kolizja(Organizm* drugiOrganizm);
};

