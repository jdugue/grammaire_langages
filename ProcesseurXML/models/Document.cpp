#include "Document.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
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

list<Element *>* Document:: getElems(){
	return elems;

}

list<PI *>* Document::getProlog(){
	return prolog;
}

string Document::getDoctype(){
	return doctype;
}
