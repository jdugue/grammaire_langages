#include "Balise.h"

Balise::Balise():Element()
{
	nom = std::string();
	nomDomaine = std::string();
	this->attributs = new list<Attribut*>();

}

Balise::Balise(char*& pNom, std::list<Attribut*> *&attributs, char*& pNomDomaine):Element()
{
	nom = std::string(pNom);
	nomDomaine = std::string(pNomDomaine);
	this->attributs = attributs;
}

Balise::Balise(char*& pNom, std::list<Attribut*> *&attributs):Element()
{
	nom = std::string(pNom);
	nomDomaine = std::string();
	this->attributs = attributs;
}

Balise::Balise(const Balise &balise): Element((Element)balise)
{
	//TODO
}

Balise::~Balise()
{
	// TODO
}

string Balise:: getNom(){
  return nom;
}

list<Attribut*>* Balise::getAttributs(){
  return attributs;
}
string Balise::getNomDomaine(){
  return nomDomaine;
}

string Balise::getValueFromAttribut(string attName)
{
	for (list<Attribut *>::iterator it = this->attributs->begin(); it != this->attributs->end(); it++)
	{
		if ( (*it)->getNom().compare(attName) == 0 )
		{
			return (*it)->getValeur();
		}

	}
	return string("");
}
	
