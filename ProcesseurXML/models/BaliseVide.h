#ifndef BALISE_VIDE_H
#define BALISE_VIDE_H
#include "Balise.h"
#include "Attribut.h"
#include <list>

class BaliseVide: public Balise
{
public:
    BaliseVide(char *, list<Attribut*>*);
    ~BaliseVide();
    BaliseVide (BaliseVide& baliseVide);

    char *toString();

private:

};

#endif