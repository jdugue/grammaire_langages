#ifndef BALISE_H
#define BALISE_H
#include "Element.h"
#include "Attribut.h"
#include <list>
#include <string>

class BaliseVide: public Element
{
public:
    Balise(string nom, list<Attribut*>*);
    ~Balise();
    Balise(Balise& balise);
    
    list<Attribut *> * getAttributs();
    string getNom();
    
    string toString();

protected:
	string nom;
	list<Attribut*> *attributs;
};

#endif
