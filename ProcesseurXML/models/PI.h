#ifndef PI_H
#define PI_H
#include "Element.h"
#include "Attribut.h"
#include <list>
#include <string>

class PI: public Element
{
public:
    PI();
    PI(char*, list<Attribut*>*, char* = (char*)"");
    ~PI();
    PI(PI& pi);
    
    // string getNom();
    // list<Attribut*>* getAtts();
    
    // string toString();

protected:
	string nom;
    string nomDomaine;
	list<Attribut*>* atts;
};

#endif
