#ifndef BALISE_H
#define BALISE_H
#include "Element.h"
#include "Attribut.h"
#include <list>
#include <string>

class Balise: public Element
{
public:
    Balise(char*&, list<Attribut*>*&, char*&);
	Balise(char*&, list<Attribut*>*&);
	Balise();
    ~Balise();
    Balise(const Balise& balise);
    
    /*list<Attribut *> * getAttributs();
    string getNom();
    
    virtual string toString() = 0;
	*/

protected:
	string nom;
	list<Attribut*> *attributs;
	string nomDomaine;
};

#endif
