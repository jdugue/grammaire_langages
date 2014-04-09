#ifndef BALISE_DOUBLE_H
#define BALISE_DOUBLE_H

#include "Balise.h"
#include <list>
#include <string>
#include "Attribut.h"

class BaliseDouble: public Balise
{
	public:
		BaliseDouble();
		BaliseDouble(char*, list<Element *> *, list<Attribut *> *, char*);

		~BaliseDouble();

		BaliseDouble (BaliseDouble& elemBalise);  //constructeur de copie   

		/*
		list<Element *> *getElements();
		string toString();
		void addElement(list<Element*>*);
		list<Element*> *getElementsByName(string name);
		*/

	private:
		list<Element *> * elements;
};

#endif
