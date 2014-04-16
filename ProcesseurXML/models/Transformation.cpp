#include "Transformation.h"
#include "BaliseDouble.h"
#include "Templates.h"



Transformation::Transformation(Document* xsl, Document* xml)
{
	this->xsl = xsl;
	this->xml = xml;
	
	
	Templates templ = Templates((BaliseDouble*)(xsl->getElementByName("stylesheet")));
	Document* newdoc = new Document();
	templ.ApplyTemplate(xml, newdoc);

}

Transformation::~Transformation()
{
}


