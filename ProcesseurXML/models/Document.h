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
		Document(list<PI *> *, char*, list<Element *> *);
		~Document();
		string Display();
		list<Element *>* getElems();
		list<PI *>* getProlog();
		string getDoctype();
		
	private:
  	list<Element *> *elems;
		list<PI *> *prolog;
		string doctype;
};

#endif
