#pragma once

#include <iostream>
using namespace std;

class Swiat;
class Organizm {
private:
	int sila;
	int inicjatywa;
	int wiek;
	pair<int, int> polozenie;
	pair<int, int> poprzedniePolozenie;
	char znak;
	bool doUsuniecia;
protected:
	Swiat* swiat;
	const int mozliwyRuch[4][2] = { 
		{0,1},
		{1,0},
		{0,-1},
		{-1,0} 
	};

public:
	Organizm(char znak, int sila, int inicjatywa, int x, int y);
	Organizm(const Organizm& a);
	int getX();
	int getY();
	int getInicjatywa();
	char getZnak();
	int getWiek();
	int getSila();
	void z¹bCzasu();
	void zabij();
	bool getDoUsuniecia();
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* drugiOrganizm) = 0;
	virtual Organizm* dziecko() = 0;
	virtual bool czyUcieczka();
	virtual string getInformacje();
	void rysuj();
	void cofnijRuch();
	void wzmocnij(int wartosc);
	void postarz(int wartosc);
	bool wykonajRuch(pair<int, int> polozenie, bool rozmnazanie);
	static int pierwszenstwo(Organizm* a, Organizm* b);		//metoda nie jest zwi¹zana z konkretnym obiektem klasy Organizm, ale z sam¹ klas¹ (nie trzeba tworzyc obiektu klasy)
	virtual ~Organizm() = default;
};