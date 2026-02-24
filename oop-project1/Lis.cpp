#include "Lis.h"
#include "Zwierze.h"
#include "Œwiat.h"


Lis::Lis(int x, int y) : Zwierze('L', 3, 7, x, y){}

void Lis::akcja()
{
	z¹bCzasu();
	pair<int, int> nowaPozycja;

	int move = rand() % 4;
	int wykonanoRuch = 0;
	for (int i = 0; i < 4; i++) {
		nowaPozycja = { getX() + mozliwyRuch[move][0], getY() + mozliwyRuch[move][1] };

		if (swiat->getOrganizm(nowaPozycja) == nullptr) {
			if (wykonajRuch(nowaPozycja, false)) {
				wykonanoRuch = 1;
				break;
			}
		}
		else if (swiat->getOrganizm(nowaPozycja)->getSila() < getSila()) {
			if (wykonajRuch(nowaPozycja, false)) {
				wykonanoRuch = 1;
				break;
			}
		}
	
		move++;
		move %= 4;
	}
	if (!wykonanoRuch) {
		swiat->dodajLog(this, "Mowi: Jestem przebiegly i nie dam sie zjesc x))");
	}
	
}

Lis* Lis::dziecko()
{
	return new Lis(*this);
}
