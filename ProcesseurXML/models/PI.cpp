#include "PI.h"

PI::PI():Element()
{
   nom = std::string();
   nomDomaine = std::string();
}

PI::PI(char* nom, std::list<Attribut*>* atts, char* nomDomaine ):Element()
{
    this->nom = std::string(nom);
    this->atts = atts;
    this->nomDomaine = std::string (nomDomaine);
}

PI::PI(PI &pi): Element((Element)pi)
{

    this->atts = pi.atts;
    this->nom = pi.nom;
    this->nomDomaine = pi.nomDomaine;
}

// std::string PI::toString()
// {
    
//     string buffer(format("<?"));
//  //   buffer.append(this->nomDomaine); //todo
//     buffer.append(this->nom);

//     for (list<Attribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++)
//     {
//         buffer.append(" ");
//         buffer.append((*it)->toString());
//     }
//     buffer.append("/>");

//     char *cstr = new char[buffer.length() + 1];
//     strcpy(cstr, buffer.c_str());
   
//     return 0;
// }
