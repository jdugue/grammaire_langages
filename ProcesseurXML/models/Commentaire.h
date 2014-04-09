#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H
#include "Element.h"
#include <string>

class Commentaire: public Element
{
public:
	Commentaire();
    Commentaire(char*&);
    ~Commentaire();
    Commentaire(Commentaire& commentaire);
    
    string getContenu();
    
    string toString();

protected:
	string contenu;
};

#endif
