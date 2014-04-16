#include "Templates.h"
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
	if (templates.find("/") != templates.end())
	{
		list<Element *> * newdocElements = newdoc->getElems();
		list<Element *> * xslElements = ((BaliseDouble*)templates.find("/")->second)->getElements();
		newdocElements->merge(*xslElements);
		
		Balise
		while ( 
	}
}

BaliseDouble* Templates::findMotherElement( string name )
{
	BaliseDouble*
}

