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

}

string Attribut::toString()
{
	string toString = "";
    return toString.append(this->nom).append("=").append("\"").append(this->valeur).append("\"");
}
