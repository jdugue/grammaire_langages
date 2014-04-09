#include "Text.h"

Text::Text():Element()
{
    contenu = new string();
}

Text::Text(char* contenu):Element()
{
    this>contenu=std::string (contenu);
}

Text::Text(Text &text): Element((Element)text)
{
    //TODO
    //this->attributs = Text.lesAttributs;
    //this->nom = Text.nom;
}


std::string Text::getContenu()
{
    return contenu;
}

std::string Text::toString()
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
