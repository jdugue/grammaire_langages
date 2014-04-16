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
		
		ApplyTemplateOnNode(newdoc->getElems());
		
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

void Templates::ApplyTemplateOnNode(list<Element*>* elems)
{
	for (  list<Element*>::iterator it = elems->begin();
								it != elems->end(); it++)
	{
		if ( dynamic_cast<BaliseDouble*>(*it))
		{
			BaliseDouble* mother = findMotherElement("apply-templates", (BaliseDouble*)*it);
			if ( mother != NULL )
			{
				// cout << mother->Display(0) << endl;
				list<Balise*> balises = mother->getElementByName("apply-templates");
				
				for ( list<Balise*>::iterator it = balises.begin();	it != balises.end(); it++)
				{
					if ( (*it)->getAttributs()->size() == 0 )
					//Cas apply-templates sans select
					{
						string nextTemplate = NextTemplate();
						if ( string != NULL )
						{
							// A FAIRE
							//TODO
						}
					}
					//Cas apply-templates select="x"
					else
					{
						
					}
				}
			}
		}
			
	}
}

string Templates::NextTemplate()
{
	list<Element *>* elementsDuXml = xml->getElems();
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
				return NULL;
			}
		}
	}
}


