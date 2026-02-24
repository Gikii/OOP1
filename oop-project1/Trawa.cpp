#include "Trawa.h"

Trawa::Trawa(int x, int y) : Roslina('t', 0, x, y) {}

Organizm* Trawa::dziecko(){
    return new Trawa(*this);
}
