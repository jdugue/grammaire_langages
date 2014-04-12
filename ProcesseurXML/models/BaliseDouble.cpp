#include "BaliseDouble.h"

BaliseDouble::BaliseDouble(): Balise()
{
	this->elements = new list<Element *>();
}

BaliseDouble::BaliseDouble(char*& nom, list<Element *> *&elements, list<Attribut *> *&attributs, char*& pNomDomaine): Balise(nom, attributs, pNomDomaine)
{
	this->elements = elements;
}

BaliseDouble::BaliseDouble(char*& nom, list<Element *> *&elements, list<Attribut *> *&attributs): Balise(nom, attributs)
{
	this->elements = elements;
}

BaliseDouble::BaliseDouble(BaliseDouble &elemBalise): Balise(elemBalise)
{
	//TODO
}

BaliseDouble::~BaliseDouble()
{
	//TODO
}
