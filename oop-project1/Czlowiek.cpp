
#include "Czlowiek.h"
#include "Œwiat.h"
#include <string>

using namespace std;

Czlowiek::Czlowiek(int x, int y) : Zwierze('C', 5, 4, x, y){
	kierunek = { 0,0 };
	umiejetnosc = -5;
}



void Czlowiek::akcja() {
	z¹bCzasu();
	pair<int, int> nowaPozycja;
	
	if (umiejetnosc > 0) {
		if (umiejetnosc == 5) {
			swiat->dodajLog(this, "Mowi: teraz was wszystkich spale HAHAH");
		}
		for (int i = 0; i < 8; i++) {
			nowaPozycja = { getX() + sasiedzi[i][0], getY() + sasiedzi[i][1] };
			if (swiat->getOrganizm(nowaPozycja) != nullptr) {
				swiat->getOrganizm(nowaPozycja)->zabij();
			}
		}
		swiat->dodajLog(this, "Zostalo " + to_string(umiejetnosc) + " tur palenia zywcem x)");

	}else if (umiejetnosc < 0 && umiejetnosc!=-5) {
		swiat->dodajLog(this, "Musi odczekac "  + to_string(umiejetnosc+5) +  " tury przed uzyciem umiejetnosci");
	}

	if (umiejetnosc > -5) {
		umiejetnosc--;
	}
	wykonajRuch({ getX() + kierunek.first, getY() + kierunek.second}, false);
	kierunek = { 0,0 };
}

bool Czlowiek::ustawKierunek(pair<int, int> kierunek) {
	if ((getX() + kierunek.first) < 0 || (getX() + kierunek.first) >= swiat->getSzerokosc() || (getY() + kierunek.second) < 0 || (getY() + kierunek.second) >= swiat->getWysokosc())
		return false;
	this->kierunek = kierunek;
	return true;
}

void Czlowiek::aktywujUmiejetnosc(){
	if (umiejetnosc == -5){
		umiejetnosc = 5;
	}
	
}

void Czlowiek::ustawCooldownUmiejetnosci(int umiejetnosc){
	this->umiejetnosc = umiejetnosc;
}

string Czlowiek::getInformacje()
{
	string dane = Zwierze::getInformacje();
	dane += to_string(umiejetnosc) + ";";
	return dane;
}

Czlowiek* Czlowiek::dziecko()
{
	return nullptr;
}

