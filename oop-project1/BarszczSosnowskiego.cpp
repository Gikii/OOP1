#include "BarszczSosnowskiego.h"
#include "Œwiat.h"
#include "Zwierze.h"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y) : Roslina('b', 10, x, y) {}

void BarszczSosnowskiego::akcja(){
	for (int i = 0; i < 4; i++) {
		auto sasiad = swiat->getOrganizm({ getX() + mozliwyRuch[i][0], getY() + mozliwyRuch[i][1] });
		if (sasiad != nullptr) {
			bool isZwierze = dynamic_cast<Zwierze*>(sasiad);
			if (isZwierze) {
				swiat->dodajLog(this, "Zatrul sasiada");
				sasiad->zabij();
			}
		}
	}
}

void BarszczSosnowskiego::kolizja(Organizm* drugiOrganizm){
	string nazwa = typeid(*drugiOrganizm).name();
	swiat->dodajLog(this, "Zatrul " + nazwa.substr(6));
	drugiOrganizm->zabij();
	zabij();
}

Organizm* BarszczSosnowskiego::dziecko(){
	return new BarszczSosnowskiego(*this);
}
