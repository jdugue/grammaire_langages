#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <list>
#include <vector>
#include "Element.h"
#include "PI.h"
using namespace std;

class Document
{
	public:
		Document();
		// Document(Element *);
		Document(list<PI *> *, string *, list<Element *> *);
		~Document();
		Element *getElems();
		string toString();
		bool hasEnTete();
		list<PI *> * getProlog();
	private:
		// string nom;
		// int type;
		list<Element *> elems;
		list<PI *> prolog;
		string doctype;
};

#endif