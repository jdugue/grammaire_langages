#ifndef BALISE_DOUBLE_H
#define BALISE_DOUBLE_H

#include "Balise.h"

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
		virtual string DisplayNoAtts();
	    list<Element*>* getElements();

	private:
		list<Element *> *elements;
};

#endif
