#include "Antylopa.h"
#include "Œwiat.h"

Antylopa::Antylopa(int x, int y) : Zwierze('A', 4, 4, x, y) {}

void Antylopa::akcja() {
	z¹bCzasu();
	int move = rand() % 8;
	for (int i = 0; i < 8; i++) {
		if (wykonajRuch({ getX() + ruchyAntylopy[move][0], getY() + ruchyAntylopy[move][1] }, false)) {
			break;
		}
		move++;
		move %= 8;
	}
}

bool Antylopa::czyUcieczka() {
	bool ucieczka = rand() % 2;
	if (ucieczka) {
		int move = 0;
		while (!wykonajRuch({ getX() + ruchyAntylopy[move][0], getY() + ruchyAntylopy[move][1] }, true)) {
			move++;
			if (move == 8) {
				swiat->dodajLog(this, "Nie udalo siê uciec");
				return false;
			}
		}
		swiat->dodajLog(this, "Udalo sie uciec");
		return true;
	}
	return false;
}

Antylopa* Antylopa::dziecko()
{
	return new Antylopa(*this);
}
