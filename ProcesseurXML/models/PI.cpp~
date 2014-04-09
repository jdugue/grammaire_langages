#include "Text.h"

PI::PI():Element()
{
   nom = new string();
}

PI::PI(std::string& nom, std::list<Attribut*>* atts):Element()
{
    this->nom = nom;
    this->atts = atts;
}

PI::PI(PI &pi): Element((Element)pi)
{

    this->atts = pi.atts;
    this->nom = pi.nom;
}


std::string PI::getNom()
{
    return nom;
}

std::list<Attribut*>* PI::getAtts()
{
    return atts;
}

std::string PI::toString()
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
