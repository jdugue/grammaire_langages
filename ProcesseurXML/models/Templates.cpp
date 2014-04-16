#include "Templates.h"
using namespace std;

Templates::~Templates()
{
}

Templates::Templates(BaliseDouble* xsl)
{
	for (list<Element *>::iterator it = xsl->getElements()->begin(); it != xsl->getElements()->end(); it++)
	{
		if ( dynamic_cast<BaliseDouble*>(*it) )
		{
			if ( ((BaliseDouble*)*it)->getNom().compare("template") == 0 )
			{
				string value = ((BaliseDouble*)*it)->getValueFromAttribut("match");
				templates[value]= ((BaliseDouble*)*it);
			}
		}
	}
}
void Templates::ApplyTemplate(Document * docxml, Document * newdoc)
{
	xml = docxml;
	if (templates.find("/") != templates.end())
	{
		list<Element *> * newdocElements = newdoc->getElems();
		list<Element *> * xslElements = ((BaliseDouble*)templates.find("/")->second)->getElements();
		newdocElements->merge(*xslElements);
		
		
		//BaliseDouble* mother = findMotherElement("apply-templates", );
		//list<Element*>::iterator it = mother->getItToElementByName("apply-templates");


		ApplyTemplateOnNode(newdoc->getElems());
		cout << newdoc->Display() << endl;
		
	}
	else
	{
		
	}
}

//Ca a l'air de marcher :)
//Parcours d'arbre en largeur
BaliseDouble* Templates::findMotherElement(string name, BaliseDouble* root )
{
	BaliseDouble* mother = root;
	//Si l'element est dans mother
	if ( mother->getElementByName(name).size()!= 0 )
	{
		return mother;
	}
	//Sinon on regarde les filsssss
	for ( list<Element*>::iterator it = mother->getElements()->begin();
									it != mother->getElements()->end(); it++)
	{
		//Mais seulement s'ils sont des BaliseDouble, bien sur
		if ( dynamic_cast<BaliseDouble*>(*it))
		{
			BaliseDouble* b = findMotherElement(name, (BaliseDouble*)*it);
			if ( b != NULL )
			{
				return b;
			}
		}
	}	
	
	return NULL;
}

void Templates::ApplyTemplateOnNode(list<Element*>* newdocElems)
{
	for (  list<Element*>::iterator it = newdocElems->begin();
								it != newdocElems->end(); it++)
	{
		if ( dynamic_cast<BaliseDouble*>(*it))
		{
			BaliseDouble* mother;
			do
			{
				BaliseDouble* mother = findMotherElement("apply-templates", (BaliseDouble*)*it);
				if ( mother != NULL )
				{
				
					list<Element*>::iterator it = mother->getItToElementByName("apply-templates");
					if ( it != mother->getElements()->end() )
					{
						string nameToFind = ((Balise*)*it)->getValueFromAttribut("select");
						it = mother->getElements()->erase(it);
						mother->getElements()->splice(it, *(templates.find(nameToFind)->second->getElements()));
						ApplyTemplateOnNode(mother->getElements());
					
					}
				}
			}while ( findMotherElement("apply-templates", (BaliseDouble*)*it));
		}
			
	}
}

string Templates::NextTemplate(list<Element *>* elementsDuXml)
{
	for (  list<Element*>::iterator it = elementsDuXml->begin();
									it != elementsDuXml->end(); it++)
	{
		if ( dynamic_cast<Balise*>(*it))
		{
			Balise* baliseDuXml = (Balise*)*it;
			if ( templates.find(baliseDuXml->getNom()) != templates.end() )
			{	
				return baliseDuXml->getNom();
			}
			else
			{
				return "";
			}
		}
	}
}



void Templates::ApplyTemplateForXml(string baliseName)
{
	list<Element *> * xslElements = ((BaliseDouble*)templates.find(baliseName)->second)->getElements();
	ApplyTemplateOnNode(xslElements);
	list<Balise*> xmlElementsToTransform = xml->getAllElementsByName(baliseName, xml->getElems());
	//newdocElements->merge(*xslElements);
}


BaliseDouble* Templates::findElementsXml(string name, BaliseDouble* root )
{
	BaliseDouble* mother = root;
	//Si l'element est dans mother
	if ( mother->getElementByName(name).size()!= 0 )
	{
		return mother;
	}
	//Sinon on regarde les filsssss
	for ( list<Element*>::iterator it = mother->getElements()->begin();
									it != mother->getElements()->end(); it++)
	{
		//Mais seulement s'ils sont des BaliseDouble, bien sur
		if ( dynamic_cast<BaliseDouble*>(*it))
		{
			BaliseDouble* b = findMotherElement(name, (BaliseDouble*)*it);
			if ( b != NULL )
			{
				return b;
			}
		}
	}	
	
	return NULL;
}

