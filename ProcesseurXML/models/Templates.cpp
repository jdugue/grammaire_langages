#include "Templates.h"

Templates::Templates(BaliseDouble* xsl)
{
	for (list<Element *>::iterator it = xsl->getElements()->begin(); it != xsl->getElements()->end(); it++)
	{
		if ( dynamic_cast<BaliseDouble*>(*it) )
		{
			if ( ((BaliseDouble*)*it)->getNom().compare("template") == 0 )
			{
				string value = ((BaliseDouble*)*it)->getValueFromAttribut(string("match"));
				//map<string,BaliseDouble*> m ;
				//m[value]= (*it);
				//templates[value] = map<string
			}
		}
	}
}
Templates::~Templates(){}
