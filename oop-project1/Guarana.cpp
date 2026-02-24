#include "Guarana.h"
#include "Œwiat.h"
#include <string>



Guarana::Guarana(int x, int y) : Roslina('g', 0, x, y) {}

void Guarana::kolizja(Organizm* drugiOrganizm){
	string nazwa = typeid(*drugiOrganizm).name();
	drugiOrganizm->wzmocnij(3);
	swiat->dodajLog(this, "Wzmocnila " + nazwa.substr(6) + " i jego sila wynosi " +  to_string(drugiOrganizm->getSila()));
	zabij();
}

Organizm* Guarana::dziecko(){
	return new Guarana(*this);
}
