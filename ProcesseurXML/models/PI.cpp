#include "PI.h"
using namespace std;

PI::PI():Element()
{
   nom = string();
   nomDomaine = string();
}

PI::PI(char* nom, list<Attribut*>* atts, char* nomDomaine ):Element()
{
    this->nom = string(nom);
    this->atts = atts;
    this->nomDomaine = string(nomDomaine);
}

PI::PI(PI &pi): Element((Element)pi)
{

    this->atts = pi.atts;
    this->nom = pi.nom;
    this->nomDomaine = pi.nomDomaine;
}

PI::~PI()
{
	// TODO
}

string PI::Display(int indent)
{
	string buffer = string();
	
	addTabs(buffer,indent);
	
	buffer.append("<?");
	
	if (!nomDomaine.empty())
	{
		buffer.append(this->nomDomaine);
		buffer.append(":"); 
	}	
	buffer.append(this->nom);

	for (list<Attribut *>::iterator it = this->atts->begin(); it != this->atts->end(); it++)
	{
		buffer.append(" ");
		buffer.append((*it)->toString());
	}
	buffer.append("?>");
	
	return buffer;
}

string PI::getNom(){
	return nom;
}
string PI::getNomDomaine(){
	return nomDomaine;
}
list<Attribut*>* PI::getAtts(){
	return atts;
}
