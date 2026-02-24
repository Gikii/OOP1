#pragma once
#include <list>
#include <algorithm>
#include "Organizm.h"
using namespace std;

class Swiat {
private:
	int szerokosc;
	int wysokosc;
	int tura;
	int iloscLogow;
	Swiat(int szerokosc, int wysokosc);
	void wyczyscLogi();
	static Swiat* instance;
	list<Organizm*> organizmy;
	Organizm* czlowiek;
public:
	static Swiat* getInstance();
	static Swiat* getInstance(int szerokosc, int wysokosc);
	static Swiat* getInstance(ifstream& plik);
	int getSzerokosc();
	int getWysokosc();
	void zaludnijSwiat();
	void WykonajTure();
	void rysujSwiat();
	void dodajLog(Organizm* zrodlo, string log);
	void dodajOrganizm(Organizm* organizm);
	void usunOrganizmy();
	void zapisz();
	Organizm* getOrganizm(pair<int, int> polozenie);
	Organizm* getCzlowiek();


};