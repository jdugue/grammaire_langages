#include "Text.h"

Text::Text():Element()
{	
	this->contenu=string(contenu);
}

Text::Text(char* contenu,int type):Element()
{
	this->contenu=string(contenu);
	this->type = type;
}

Text::Text(const Text &text)
{
    //TODO
    //this->attributs = Text.lesAttributs;
    //this->nom = Text.nom;
}

string Text::Display(int indent)
{
	string disp = string();
	if (type == 1 ) // texte simple
	{
		addTabs(disp,indent);
	
		disp.append(contenu);
	}
	else // CDATA
	{
		disp.append("<![CDATA[");
		disp.append(contenu);
		disp.append("]]>");
	}
	
	return disp;
}

Text::~Text()
{
	
}

int Text::getType(){
	return type;
}

string Text::getContenu(){
	return contenu;
}
