#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <list>
#include <vector>
#include "PI.h"

using namespace std;

class Document
{
	public:
		Document();
		Document(list<PI *> *, char*, list<PI *> *,list<Element *> *);
		~Document();
		string Display();
		list<Element *>* getElems();
		list<PI*>* getProlog_before();
		string getDoctype();
		Element* getElementByName(string name);
		
	private:
  		list<Element *> *elems;
		list<PI *> *prolog_before;
		list<PI *> *prolog_after;
		string doctype;
};

#endif
