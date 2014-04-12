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

string Document::Display()
{
	string buffer;
	for (list<PI *>::iterator it = this->prolog->begin(); it != this->prolog->end(); it++)
	{
		buffer.append((*it)->Display());
	}
	buffer.append(doctype);
	for (list<Element *>::iterator it = this->elems->begin(); it != this->elems->end(); it++)
	{
		buffer.append((*it)->Display());
	}
	return buffer;
}
