#ifndef BALISE_VIDE_H
#define BALISE_VIDE_H
#include "Balise.h"
#include "Attribut.h"
#include <list>
#include <string>

class BaliseVide: public Balise
{
public:
    BaliseVide(char* , list<Attribut*>*, char*="");
    ~BaliseVide();
    BaliseVide (BaliseVide& baliseVide);

    // string toString();

private:

};

#endif
