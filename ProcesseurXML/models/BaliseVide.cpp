#include "BaliseVide.h"


BaliseVide::BaliseVide(std::string pNom, std::list<Attribut*> *attributs):Balise(pNom, attributs)
{

}

BaliseVide::BaliseVide(BaliseVide &baliseVide): Element((Element)elemBaliseOrph)
{
	//TODO
    this->attributs = elemBaliseOrph.lesAttributs;
    this->nom = elemBaliseOrph.nom;
}

BaliseVide::~BaliseVide()
{
    
}

std::string BaliseVide::toString()
{
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
    return cstr;
}
