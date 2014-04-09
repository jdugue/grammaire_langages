#ifndef TEXT_H
#define TEXT_H
#include "Element.h"
#include "Attribut.h"
#include <list>
#include <string>

class PI: public Element
{
public:
    PI(string&, list<Attribut*>*, string& nomDomaine= "");
    ~PI();
    PI(PI& pi);
    
    string getNom();
    list<Attribut*>* getAtts();
    
    string toString();

protected:
	string nom;
        string nomDomaine;
	list<Attribut*>* atts;
};

#endif
