#include "Transformation.h"
#include "BaliseDouble.h"
#include "Templates.h"



Transformation::Transformation(Document* xsl, Document* xml)
{
	this->xsl = xsl;
	this->xml = xml;
}

Transformation::~Transformation()
{
}

string Transformation::transform()
{
	if ( xsl != NULL && xml != NULL )
	{
		BaliseDouble* stsheet = (BaliseDouble*) xsl->getElementByName(string("stylesheet"));
		if ( stsheet != NULL )
		{ 
			cout << stsheet->Display(4) << endl;
			Templates t = Templates(stsheet);
		}
		
	} 
} 
