#ifndef BALISE_DOUBLE_H
#define BALISE_DOUBLE_H

#include "Balise.h"
#include <map>

using namespace std;

class BaliseDouble: public Balise
{
	public:
		BaliseDouble();
		BaliseDouble(char*&, list<Element *> *&, list<Attribut *> *&);
 		BaliseDouble(char*&, list<Element *> *&, list<Attribut *> *&, char*& pNomDomaine);
		~BaliseDouble();
		BaliseDouble (BaliseDouble& elemBalise);   
		string Display(int indent);
	    list<Element*>* getElements();
		list<Balise*> getElementByName(string name);

	private:
		list<Element *> *elements;
};

#endif
