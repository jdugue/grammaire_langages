#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <list>
#include <vector>
#include "Element.h"
using namespace std;

class Document
{
	public:
		Document();
		Document(Element *);
		Document(string *, int *, list<Element *> *,list<PI *> *, string *);
		~Document();
		Element *getElems();
		char *toString();
		bool hasEnTete();
		list<EnTete *> *getProlog();
	private:
		string nom;
		int type;
		list<Element *> elems;
		list<PI *> prolog
		string doctype;
};

#endif