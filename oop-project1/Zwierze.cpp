#include "Zwierze.h"
#include "Świat.h"
#include <iostream>

using namespace std;

Zwierze::Zwierze(char znak, int sila, int inicjatywa, int x, int y) : Organizm(znak, sila, inicjatywa, x, y) {}

void Zwierze::akcja() {
	ząbCzasu();
	int move = rand() % 4;
	for (int i = 0; i < 4; i++) {
		if (wykonajRuch({ getX() + mozliwyRuch[move][0], getY() + mozliwyRuch[move][1] }, false)) {
			break;
		}
		move++;
		move%=4;
	}
}

void Zwierze::kolizja(Organizm* drugiOrganizm) {
	if (typeid(*this) == typeid(*drugiOrganizm)) {
		if (getWiek() < 2 || drugiOrganizm->getWiek() < 2) {	//cooldown na rozmnazanie
			return;
		}
		auto dziecko = dynamic_cast<Zwierze*>(this->dziecko());
		int move = rand() % 4;
		int miejsceNarodzin = 0;
		for (int i = 0; i < 4; i++) {
			if (wykonajRuch({ getX() + mozliwyRuch[move][0], getY() + mozliwyRuch[move][1] }, true)) {
				miejsceNarodzin = 1;
				swiat->dodajLog(this, "Rozmnazanie");
				swiat->dodajLog(this, "Mowi: Jest nas coraz wiecej, HAHAH");
				break;
			}
			move++;
			move %= 4;
		}
		if (!miejsceNarodzin) {	
			swiat->dodajLog(this, "Nie ma miejsca na narodziny. Dzieciak musi umrzec!");
			dziecko->zabij();
			return;
		}


	}
	else if (czyUcieczka() || drugiOrganizm->czyUcieczka()){
		return;
	}
	else if (getSila() > drugiOrganizm->getSila()){
		string nazwa = typeid(*drugiOrganizm).name();
		swiat->dodajLog(this, "Pokonal w walce " + nazwa.substr(6));
		drugiOrganizm->zabij();
	}
	else if (getSila() < drugiOrganizm->getSila()) {
		string nazwa = typeid(*drugiOrganizm).name();
		swiat->dodajLog(this, "Przegral walke z " + nazwa.substr(6));
		this->zabij();
	}
	else{
		string nazwa = typeid(*drugiOrganizm).name();
		swiat->dodajLog(this, "oraz " + nazwa.substr(6)+ " umieraja w stoczonej bitwie");
		zabij();
		drugiOrganizm->zabij();
	}
	
}