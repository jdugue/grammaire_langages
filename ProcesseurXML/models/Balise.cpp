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

Balise::Balise(const Balise &balise)
{
	this->nom = balise.nom;
	this->nomDomaine = balise.nomDomaine;
	this->attributs = new list<Attribut*>();

	for (list<Attribut *>::iterator it = balise.attributs->begin(); it != balise.attributs->end(); it++)
  	{
		Attribut * tmp = new Attribut(**it);
  	 	this->attributs->push_back(tmp);
  	}
}

Balise::~Balise()
{
	for (list<Attribut *>::iterator it = this->attributs->begin(); it != this->attributs->end(); it++)
  	{
  	  delete *it;
  	}
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

Attribut* Balise::getAttribut(const string& name)
{
	for (list<Attribut *>::iterator it = this->attributs->begin(); it != this->attributs->end(); it++)
	{
		if ((*it)->getNom() == name)
		{
			return (*it);
		}
	}
	return NULL;
}
	
