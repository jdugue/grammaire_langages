#include "Commentaire.h"

Commentaire::Commentaire():Element()
{
	contenu = std::string();
}

Commentaire::Commentaire(char*& contenu):Element()
{
	this->contenu = std::string (contenu);
}

Commentaire::Commentaire(Commentaire &commentaire): Element((Element)commentaire)
{
	this->contenu = commentaire.contenu;
}

Commentaire::~Commentaire()
{
	// TODO
}

string Commentaire::Display (int indent)
{
	return contenu;
}
