#include "Text.h"

Text::Text():Element()
{	
	this->contenu=std::string(contenu);
}

Text::Text(char* contenu):Element()
{
	this->contenu=std::string(contenu);
}

Text::Text(Text &text): Element((Element)text)
{
    //TODO
    //this->attributs = Text.lesAttributs;
    //this->nom = Text.nom;
}
