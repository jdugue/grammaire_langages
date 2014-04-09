#include "BaliseVide.h"
using namespace std;

BaliseVide::BaliseVide(char*& pNom, std::list<Attribut*> *&attributs, char*& pNomDomaine):Balise(pNom, attributs,pNomDomaine)
{

}

BaliseVide::BaliseVide(BaliseVide &baliseVide): Balise((Balise)baliseVide)
{
	//TODO
    //this->attributs = elemBaliseOrph.attributs;
    //this->nom = elemBaliseOrph.nom;
}

BaliseVide::~BaliseVide()
{
    
} 

// string BaliseVide::toString()
// {
	
//     string buffer(format("<"));

//     // buffer.append(this->type);
//     buffer.append(":");
//     buffer.append(this->nom);

//     for (list<Attribut *>::iterator it = this->attributs->begin(); it != this->attributs->end(); it++)
//     {
//         buffer.append(" ");
//         buffer.append((*it)->toString());
//     }
//     buffer.append("/>");

//     char *cstr = new char[buffer.length() + 1];
//     strcpy(cstr, buffer.c_str()); 
    
//     return 0;
// }
