#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <string>
#include <stdio.h>
#include "Document.h"

using namespace std;

class Transformation
{
	public:
		Transformation(Document* xsl, Document* xml); 
		~Transformation();
	private:
		Document* xsl;
		Document* xml;
};


#endif
