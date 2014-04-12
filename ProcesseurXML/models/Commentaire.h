#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H
#include "Element.h"

class Commentaire: public Element
{
	public:
		Commentaire();
    Commentaire(char*&);
    ~Commentaire();
    Commentaire(Commentaire& commentaire);
    string Display (int indent);

	protected:
		string contenu;
};

#endif
