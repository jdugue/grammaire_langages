#ifndef BALISE_VIDE_H
#define BALISE_VIDE_H
#include "Balise.h"
#include "Attribut.h"
#include <list>
#include <string>

class BaliseVide: public Balise
{
public:
    BaliseVide(string& , list<Attribut*>*, string&);
    ~BaliseVide();
    BaliseVide (BaliseVide& baliseVide);

    string toString();

private:

};

#endif
