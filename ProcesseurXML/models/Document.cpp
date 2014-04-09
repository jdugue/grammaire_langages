#include "Document.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
using namespace std;

Document::Document()
{

}

Document::Document(list<PI *> prolog, string *doctype, list<Element *> *elems)
{
	// this->nom = nom;
	// this->type = type;
	this->elems = elems;
	this->prolog = prolog;
	this->doctype = doctype;
}

// Document::Document(Element *elementRacine)
// {
// 	this->enTetes = new list<EnTete *>();
// 	this->elementRacine = elementRacine;
// }

Document::~Document()
{
	delete(this->enTetes);
	delete(this->nom);
	delete(this->type);
	delete(this->elems);
	delete(this->prolog);
	delete(this->doctype);

}

// Element *Document::getRacine()
// {
// 	return this->elementRacine;
// }

// string Document::toString()
// {
// 	// nbTab = 0;
// 	// string buffer("");
// 	// for (list<EnTete *>::iterator it = this->enTetes->begin(); it != this->enTetes->end(); it++)
// 	// {
// 	// 	buffer.append((*it)->toString());
// 	// 	buffer.append("\n");
// 	// }
// 	// buffer.append(this->elementRacine->toString());
// 	// char *cstr = new char[buffer.length() + 1];
// 	// strcpy(cstr, buffer.c_str());
// 	return 0;
// }

// bool Document::hasEnTete()
// {
// 	return !(this->enTetes->empty());
// }

// list<PI *> *Document::getProlog()
// {
// 	return this->prolog;
// }