#ifndef BALISE_DOUBLE_H
#define BALISE_DOUBLE_H

#include "Element.h"
#include <list>
#include <string>
#include "Attribut.h"

class BaliseDouble: public Balise
{
	public:
		BaliseDouble();
		BaliseDouble (BaliseDouble& elemBalise);  //constructeur de copie   
		list<Attribut *> *getAttributs();
		list<Element *> *getElements();
		string getNom();
		string getType();
		BaliseDouble(string &, list<Element *> *, list<Attribut *> *&, string );
		~BaliseDouble();
		string toString();
		void addElement(list<Element*>*);
		list<Element*> *getElementsByName(string name);

	private:
		string type;
		string nom;
		list<Attribut *> *lesAttributs;
		list<Element *> *lesElements;
};

#endif