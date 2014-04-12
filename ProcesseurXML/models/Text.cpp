#include "Text.h"

Text::Text():Element()
{	
	this->contenu=string(contenu);
}

Text::Text(char* contenu):Element()
{
	this->contenu=string(contenu);
}

Text::Text(Text &text): Element((Element)text)
{
    //TODO
    //this->attributs = Text.lesAttributs;
    //this->nom = Text.nom;
}

string Text::Display()
{
	return string(this->contenu);
}

Text::~Text()
{
	// TODO
}
