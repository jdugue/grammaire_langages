#include "Document.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
using namespace std;

Document::Document()
{

}

Document::Document(list<PI *>* prolog, char* doctype, list<Element *> *elems)
{
	this->elems = elems;
	this->prolog = prolog;
	this->doctype = string(doctype);
}

Document::~Document()
{
	// TODO
}
