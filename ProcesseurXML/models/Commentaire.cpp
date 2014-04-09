#include "Commentaire.h"

Commentaire::Commentaire():Element()
{
    contenu = new string();
}

Commentaire::Commentaire(char* contenu):Element()
{
    this->contenu = std::string (contenu);
}

Commentaire::Commentaire(Commentaire &commentaire): Element((Element)commentaire)
{
    //TODO
    //this->attributs = Text.lesAttributs;
    //this->nom = Text.nom;
}


std::string Commentaire::getContenu()
{
    return contenu;
}

std::string Commentaire::toString()
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
