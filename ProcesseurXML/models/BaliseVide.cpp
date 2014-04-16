#include "BaliseVide.h"
using namespace std;

BaliseVide::BaliseVide(char*& pNom, std::list<Attribut*> *&attributs, char*& pNomDomaine):Balise(pNom, attributs,pNomDomaine)
{
}

BaliseVide::BaliseVide(char*& pNom, std::list<Attribut*> *&attributs):Balise(pNom, attributs)
{
}


BaliseVide::BaliseVide(BaliseVide &baliseVide): Balise(baliseVide)
{
}

BaliseVide::~BaliseVide()
{
	   
} 

string BaliseVide::Display (int indent)
{
	
	string mybalise = string();
	
	addTabs(mybalise,indent);
	
	mybalise.append("<");
	
	if (!nomDomaine.empty())
	{
		mybalise.append(nomDomaine);
		mybalise.append(":");
	}
	mybalise.append(nom);

	for (list<Attribut *>::iterator it = this->attributs->begin(); it != this->attributs->end(); it++)
	{
		mybalise.append(" ");
		mybalise.append((*it)->toString());
	}
	
	mybalise.append("/>");
	
	return mybalise;
}

string BaliseVide::DisplayNoAtts()
{
	/* Rien à faire */
}
