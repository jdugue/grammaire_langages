#include "Document.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
using namespace std;

Document::Document()
{
	this->prolog = new list<PI*>();
	this->elems = new list<Element*>();
	this->doctype = string();
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
	string buffer = string();
	for (list<PI *>::iterator it = this->prolog->begin(); it != this->prolog->end(); it++)
	{
		buffer.append((*it)->Display(0));
		buffer.append("\n");
	}
	buffer.append(doctype);
	buffer.append("\n");
	for (list<Element *>::iterator it = this->elems->begin(); it != this->elems->end(); it++)
	{
		buffer.append((*it)->Display(0));
		buffer.append("\n");
	}
	// Suppression dernier saut de ligne
	return buffer.erase(buffer.size()-1);
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
