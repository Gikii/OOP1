#include "WilczeJagody.h"
#include "Œwiat.h"

WilczeJagody::WilczeJagody(int x, int y) : Roslina('w', 99, x, y){}

void WilczeJagody::kolizja(Organizm* drugiOrganizm){
	string nazwa = typeid(*drugiOrganizm).name();
	swiat->dodajLog(this, "Zatruly " + nazwa.substr(6));
	drugiOrganizm->zabij();
	zabij();
}

Organizm* WilczeJagody::dziecko(){
	return new WilczeJagody(*this);
}
