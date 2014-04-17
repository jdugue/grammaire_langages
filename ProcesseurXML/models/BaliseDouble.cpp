#include "BaliseDouble.h"

BaliseDouble::BaliseDouble(): Balise()
{
	this->elements = new list<Element *>();
}

BaliseDouble::BaliseDouble(char*& nom, list<Element *> *&elements, list<Attribut *> *&attributs, char*& pNomDomaine): Balise(nom, attributs, pNomDomaine)
{
	this->elements = elements;
}

BaliseDouble::BaliseDouble(char*& nom, list<Element *> *&elements, list<Attribut *> *&attributs): Balise(nom, attributs)
{
	this->elements = elements;
}

BaliseDouble::BaliseDouble(BaliseDouble &elemBalise): Balise(elemBalise)
{
	//TODO
}

BaliseDouble::~BaliseDouble()
{
  //todo
  //for (list<Attribut *>::iterator it = this->attributs->begin(); it != this->attributs->end(); it++)
  //	{
  //	  delete &it;
  //	}
	
}

string BaliseDouble::Display (int indent)
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
	
	mybalise.append(">\n");
	
	for (list<Element *>::iterator it = this->elements->begin(); it != this->elements->end(); it++)
	{
		mybalise.append((*it)->Display(indent+1));
		mybalise.append("\n");
	}
	
	addTabs(mybalise,indent);
	mybalise.append("</");
	
	if (!nomDomaine.empty())
	{
		mybalise.append(nomDomaine);
		mybalise.append(":");
	}
	
	mybalise.append(nom);
	mybalise.append(">");
	
	return mybalise;
}

list<Element*>* BaliseDouble::getElements(){
  return elements;
}

list<Balise*> BaliseDouble::getElementByName(string name)
{
	list<Balise*> balises;
	for (list<Element *>::iterator it = this->elements->begin(); it != this->elements->end(); it++)
	{
		if ( dynamic_cast<Balise*>(*it))
		{
			if (((Balise*)(*it))->getNom().compare(name) == 0 )
			{
				balises.push_back((Balise*)*it);
			}		
		}

	}
	return balises;
}

list<Element*>::iterator BaliseDouble::getItToElementByName(string name)
{
	list<Element*>::iterator it;
	for (it = this->elements->begin(); it != this->elements->end(); it++)
	{
		if ( dynamic_cast<Balise*>(*it))
		{
			if (((Balise*)(*it))->getNom().compare(name) == 0 )
			{
				return it;
			}		
		}

	}
	return this->elements->end();
}

list<Element*>* BaliseDouble::getCopyOfElements()
{
	list<Element*>* newList = new list<Element*>();
	for (list<Element*>::iterator it = this->elements->begin(); it != this->elements->end(); it++)
	{
		newList->push_back(*it);
	}
	return newList;
}

