#include "Attribut.h"

#include <iostream>
using namespace std;

Attribut::Attribut(string pNom, string pValeur)
{
    this->nom = pNom;
    this->valeur = pValeur;
}

Attribut::Attribut(const Attribut& attr)
{
    // this->valeur = attr.getValeur();
    // this->nom = attr.getNom();
    cout<< "..."<<endl<<endl;
}

string Attribut::getValeur()
{
    return this->valeur;
}

string Attribut::getNom()
{
    return this->nom;
}

Attribut::~Attribut()
{
    delete(this->nom);
    delete(this->valeur);
}

string Attribut::toString()
{
    return strcat(strcat(strcat(this->nom, "=\""), this->valeur), "\"");
}
