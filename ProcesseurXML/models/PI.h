#ifndef PI_H
#define PI_H
#include "Element.h"

class PI: public Element
{
	public:
    PI();
    PI(char*, list<Attribut*>*, char* = (char*)"");
    ~PI();
    PI(const PI& pi);
    string Display (int indent);
    virtual string DisplayNoAtts();
	string getNom();
	string getNomDomaine();
	list<Attribut*>* getAtts();

	protected:
	string nom;
    	string nomDomaine;
	list<Attribut*>* atts;
};

#endif
