#include "Roœlina.h"
#include "Œwiat.h"

Roslina::Roslina(char znak, int sila, int x, int y) : Organizm(znak, sila, 0, x, y){}

void Roslina::akcja(){
	bool zasianie = rand() % 150 == 10;	//ustawiamy prawdopodobienstwo zasiania
	if (zasianie) {
		auto dziecko = dynamic_cast<Roslina*>(this->dziecko());
		int move = rand() % 4;

		int miejsceNarodzin = 0;
		for (int i = 0; i < 4; i++) {
			if (wykonajRuch({ getX() + mozliwyRuch[move][0], getY() + mozliwyRuch[move][1] }, true)) {
				miejsceNarodzin = 1;
				swiat->dodajLog(this, "Rozsiewanie");
				break;
			}
			move++;
			move %= 4;
		}
		if (!miejsceNarodzin) {
			swiat->dodajLog(this, "Nie ma miejsca na rozsianie");
			dziecko->zabij();
			return;
		}


	}
}

void Roslina::kolizja(Organizm* drugiOrganizm){

	string nazwa = typeid(*drugiOrganizm).name();

	if (getSila() > drugiOrganizm->getSila())
	{
		swiat->dodajLog(this, "Zatrula " + nazwa.substr(6));
		drugiOrganizm->zabij();
	}
	else if (getSila() < drugiOrganizm->getSila())
	{
		swiat->dodajLog(this, "Zostala zdeptana przez " + nazwa.substr(6));
		zabij();
	}

}
