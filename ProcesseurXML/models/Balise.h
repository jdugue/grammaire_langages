#ifndef BALISE_H
#define BALISE_H
#include "Element.h"

class Balise: public Element
{
	public:
		Balise(char*&, list<Attribut*>*&, char*&);
		Balise(char*&, list<Attribut*>*&);
		Balise();
		~Balise();
		Balise(const Balise& balise);
		virtual string Display(int indent)
		{
	  		return string();
		}	
		string getNom();
		list<Attribut*>* getAttributs();
		Attribut* getAttribut(const string& name);
		string getNomDomaine();
		virtual list<Element*>* getElements()
		{
			return NULL;
		}
	
	protected:
		string nom;
		list<Attribut*> *attributs;
		string nomDomaine;
};

#endif
