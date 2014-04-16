#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
#include <list>
#include <map>
#include <string>
#include "BaliseDouble.h"
#include "Document.h"

using namespace std;

class Templates
{
	public:
		Templates(BaliseDouble*);
		~Templates();
		void ApplyTemplate(Document * docxml, Document * newdoc);
		BaliseDouble* findMotherElement(string name, BaliseDouble* root );
		void ApplyTemplateOnNode(list<Element*>*);
		std::string NextTemplate();
		
	private:
  		map<string, BaliseDouble*> templates;
		Document* xml;
		
};

#endif
