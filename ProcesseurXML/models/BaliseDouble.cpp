#include "BaliseDouble.h"

BaliseDouble::BaliseDouble(): Balise()
{
	// this->lesAttributs = new list<Attribut *>();
    // this->lesElements = (list<Element*>**) calloc(2, sizeof(list<Element*>*));
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

BaliseDouble::BaliseDouble(BaliseDouble &elemBalise): Balise((Balise)elemBalise)
{
	//TODO
    //this->lesAttributs = elemBalise.lesAttributs;
    //this->elements = elemBalise.elements;
    //this->nom = elemBalise.nom;
    //this->type = elemBalise.type;
}

BaliseDouble::~BaliseDouble()
{
	//delete lesAttributs;
	//delete nom;
}

/*
list<Element *> *BaliseDouble::getElements()
{
	return elements;
}

list<Element *> *BaliseDouble::getElementsByName(string name)
{
	// list<Element *> *elementsOk = new list<Element *>();
	// for (list<Element *>::iterator it = this->lesElements->begin(); it != this->lesElements->end(); it++)
	// {
	// 	// if (strcmp((*it)->getName, name) == 0)
	// 	// {
	// 	//     elementsOk->push_back(*it);
	// 	// }
	// }
	return 0 ;//elementsOk;
}

string BaliseDouble::toString()
{
	string toString = "<";
	if (this->nomDomaine.compare("") == 1 )  // Si nomDomaine est pas vide
	{
		toString.append(nomDomaine).append(":");
	}
	toString.append(nom);
	for (list<Attributs*>::const_iterator ci = attributs->begin(); ci != attributs->end())
	{
		toString.append(" ");	
	}
    return 0;
}

void BaliseDouble::addElement(list<Element*>* elem){
    this->elements->insert(this->lesElements->begin(),elem->begin(),elem->end());
}
*/
