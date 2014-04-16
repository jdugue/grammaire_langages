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
		string NextTemplate(list<Element *>*);
		void ApplyTemplateForXml(string baliseName);
		BaliseDouble* findElementsXml(string name, BaliseDouble* root );
		
	private:
  		map<string, BaliseDouble*> templates;
		Document* xml;
		
};

#endif
