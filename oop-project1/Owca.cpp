#include "Owca.h"

Owca::Owca(int x, int y) : Zwierze('O', 4, 4, x, y){}

Owca* Owca::dziecko()
{
    return new Owca(*this);
}
