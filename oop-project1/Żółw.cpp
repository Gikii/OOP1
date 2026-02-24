#include "¯ó³w.h"
#include "Œwiat.h"

Zolw::Zolw(int x, int y) : Zwierze('Z', 2, 1, x, y){}

void Zolw::akcja(){

    bool robiRuch = (rand() % 100) >= 75;
    if (robiRuch) {
        Zwierze::akcja();

    }
    else
        z¹bCzasu();
}

void Zolw::kolizja(Organizm* drugiOrganizm){

    if (drugiOrganizm->getSila() < 5 && typeid(*this) != typeid(*drugiOrganizm)) {
        string nazwa = typeid(*drugiOrganizm).name();
        swiat->dodajLog(this, "Odparl atak " + nazwa.substr(6));
        drugiOrganizm->cofnijRuch();
    }
    else
        Zwierze::kolizja(drugiOrganizm);
}

Zolw* Zolw::dziecko(){

    return new Zolw(*this);
}

