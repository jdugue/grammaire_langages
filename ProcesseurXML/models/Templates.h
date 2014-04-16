#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
#include <list>
#include <map>
#include "BaliseDouble.h"
#include "Document.h"

using namespace std;

class Templates
{
	public:
		Templates(BaliseDouble*);
		~Templates();
		void ApplyTemplate(Document * docxml, Document * newdoc);
		
	private:
  		map<string, BaliseDouble*> templates;
		
};

#endif
