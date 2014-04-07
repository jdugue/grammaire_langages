#include "Balise.h"

Balise::Balise():Element()
{
	nom = new string();
	this->attributs = new list<Attribut*>();

}

Balise::Balise(std::string& pNom, std::list<Attribut*> *attributs):Element()
{
	nom (pNom);
	this->attributs = attributs;

}

Balise::Balise(BaliseVide &baliseVide): Element((Element)baliseVide)
{
	//TODO
    //this->attributs = elemBaliseOrph.lesAttributs;
    //this->nom = elemBaliseOrph.nom;
}

std::string Balise::getNom()
{
	return nom;
}

std::list<Attribut *> * BaliseVide::getAttributs()
{
	return attributs;
}

std::string Balise::toString()
{
	/*
    string buffer(format("<"));

    buffer.append(this->type);
    buffer.append(":");
    buffer.append(this->nom);

    for (list<Attribut *>::iterator it = this->lesAttributs->begin(); it != this->lesAttributs->end(); it++)
    {
        buffer.append(" ");
        buffer.append((*it)->toString());
    }
    buffer.append("/>");

    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    */
    return 0;
}
