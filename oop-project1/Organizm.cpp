#include "Organizm.h"
#include "Œwiat.h"
#include <string>


Organizm::Organizm(char znak, int sila, int inicjatywa, int x, int y) {
	this->swiat = Swiat::getInstance();
	this->znak = znak;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->polozenie = { x, y };
	this->wiek = 0;
	swiat->dodajOrganizm(this);
	this->doUsuniecia = false;
}

Organizm::Organizm(const Organizm& a)
{
	this->swiat = a.swiat;
	this->znak = a.znak;
	this->sila = a.sila;
	this->inicjatywa = a.inicjatywa;
	this->polozenie = a.polozenie;
	this->wiek = 0;
	swiat->dodajOrganizm(this);
	this->doUsuniecia = false;
}

int Organizm::getX()
{
	return polozenie.first;
}

int Organizm::getY()
{
	return polozenie.second;
}


int Organizm::getInicjatywa()
{
	return inicjatywa;
}


char Organizm::getZnak()
{
	return znak;
}

int Organizm::getWiek() {
	return wiek;
}

int Organizm::getSila() {
	return sila;
}

bool Organizm::getDoUsuniecia() {
	return doUsuniecia;
}

string Organizm::getInformacje()
{
	string out = "";
	out += typeid(*this).name();
	out += ";";
	out += to_string(polozenie.first);
	out += ";";
	out += to_string(polozenie.second);
	out += ";";
	out += to_string(sila);
	out += ";";
	out += to_string(wiek);
	out += ";";
	return out;
}

int Organizm::pierwszenstwo(Organizm* a, Organizm* b)
{
	if (a->inicjatywa > b->inicjatywa)
		return 1;
	else if (a->inicjatywa < b->inicjatywa)
		return 0;
	else
	{
		if (a->wiek > b->wiek)
			return 1;
		else
			return 0;
	}
}



void Organizm::z¹bCzasu() {
	wiek++;
}

void Organizm::postarz(int wartosc)
{
	wiek += wartosc;
}

void Organizm::zabij()
{
	polozenie = { -1, -1 };
	sila = -1;
	inicjatywa = -1;
	doUsuniecia = true;
}

void Organizm::wzmocnij(int wartosc){
	sila += wartosc;
}

bool Organizm::czyUcieczka() {		//domyslnie organizm nie ucieka, wyjatkiem jest antylopa
	return false;
}

void Organizm::rysuj()
{
	cout << "\033[" << polozenie.second + 2 << ";" << polozenie.first * 2 + 2 << "H";
	cout << znak;
}

void Organizm::cofnijRuch() {
	wykonajRuch(poprzedniePolozenie, false);

}

bool Organizm::wykonajRuch(pair<int, int> polozenie, bool rozmnazanie) {
	if (polozenie.first < 0 || polozenie.first >= swiat->getSzerokosc() || polozenie.second < 0 || polozenie.second >= swiat->getWysokosc())
		return false;
	if (rozmnazanie && swiat->getOrganizm(polozenie) != nullptr) {	//zapobiegniecie natychmiastowego rozmnozeniu sie z rodzicem w tej samej turze
		return false;
	}
	
	poprzedniePolozenie = this->polozenie;

	Organizm* drugiOrganizm = swiat->getOrganizm(polozenie);
	this->polozenie = polozenie;
	if (drugiOrganizm != nullptr && drugiOrganizm->getSila()>-1)
	{
		drugiOrganizm->kolizja(this);
	}
	return true;
}