// oop-project1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


#include "Świat.h"
#include <iostream>
#include <conio.h>
#include "Czlowiek.h"
#include <fstream>
#include <string>

using namespace std;

enum klawisze { gora = 72, dol = 80, lewo = 75, prawo = 77, umiejetnosc = ' ', enter = 13, zapisz = 's', wczytaj = 'l' };

int main(){
    

    int szerokoscPlanszy, wysokoscPlanszy;
    cout << "Podaj wysokosc planszy: ";
    cin >> wysokoscPlanszy;
    cout << "Podaj szerokosc planszy: ";
    cin >> szerokoscPlanszy;

    Swiat* swiat = Swiat::getInstance(szerokoscPlanszy, wysokoscPlanszy);
    swiat->zaludnijSwiat();
    swiat->rysujSwiat();
    char klawisz;
    ifstream lista_plikow;
    ifstream plik;
    string linia;

    while (true) {
        
        Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(swiat->getCzlowiek());

        klawisz = _getch();
        if (czlowiek != nullptr) {
            if (klawisz == gora) {
                if (czlowiek->ustawKierunek({ 0,-1 })) {
                    swiat->WykonajTure();
                    swiat->rysujSwiat();
                }
            }
            else if (klawisz == dol) {
                if (czlowiek->ustawKierunek({ 0,1 })) {
                    swiat->WykonajTure();
                    swiat->rysujSwiat();
                }
            }
            else if (klawisz == prawo) {
                if (czlowiek->ustawKierunek({ 1,0 })) {
                    swiat->WykonajTure();
                    swiat->rysujSwiat();
                }
            }
            else if (klawisz == lewo) {
                if (czlowiek->ustawKierunek({ -1,0 })) {
                    swiat->WykonajTure();
                    swiat->rysujSwiat();
                }
            }
            else if (klawisz == umiejetnosc) {
                czlowiek->aktywujUmiejetnosc();
                swiat->WykonajTure();
                swiat->rysujSwiat();
            }
        }

        if (klawisz == enter) {
            swiat->WykonajTure();
            swiat->rysujSwiat();
        }
        else if (klawisz == zapisz) {
            swiat->zapisz();
        }
        else if (klawisz == wczytaj) {
            cout << "\x1B[2J\033[0;0H";
            lista_plikow.open("saves");
            while (getline(lista_plikow, linia, ';'))
            {
                cout << linia << " - ";
                getline(lista_plikow, linia);
                cout << linia << endl;
            }
            cout << "Podaj nr pliku do wczytania (0 = anuluj): ";
            int numer;
            cin >> numer;
            plik = ifstream("save" + to_string(numer));
            if (plik.is_open()) {
                swiat = Swiat::getInstance(plik);

            }
            swiat->rysujSwiat();
            plik.close();
            lista_plikow.close();
        }

        
    }

    return 0;
    
}
