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
	// TODO   
} 
