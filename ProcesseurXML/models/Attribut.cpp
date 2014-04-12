#include "Attribut.h"

#include <iostream>
using namespace std;

Attribut::Attribut(char* pNom, char* pValeur)
{
    this->nom = string(pNom);
    this->valeur = string(pValeur);
}

Attribut::Attribut(const Attribut& attr)
{
    this->valeur = attr.valeur;
    this->nom = attr.nom;
}

Attribut::~Attribut()
{
	// TODO
}
