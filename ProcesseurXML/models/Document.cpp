#include "Document.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
using namespace std;

Document::Document()
{
	this->prolog_before = new list<PI*>();
	this->prolog_after = new list<PI*>();
	this->elems = new list<Element*>();
	this->doctype = string();
}

Document::Document(list<PI *>* prolog_b, char* doctype, list<PI *>* prolog_a, list<Element *> *elems)
{
	this->elems = elems;
	this->prolog_before = prolog_b;
	this->prolog_after = prolog_a;
	this->doctype = string(doctype);
}

Document::~Document()
{
	
	for (list<PI *>::iterator it = this->prolog_before->begin(); it != this->prolog_before->end(); it++)
  	{
  		delete *it;
  	}

	for (list<PI *>::iterator it = this->prolog_after->begin(); it != this->prolog_after->end(); it++)
  	{
  		delete *it;
  	}

	for (list<Element *>::iterator it = this->elems->begin(); it != this->elems->end(); it++)
  	{
  		delete *it;
  	}
}

string Document::Display()
{
	string buffer = string();
	for (list<PI *>::iterator it = this->prolog_before->begin(); it != this->prolog_before->end(); it++)
	{
		buffer.append((*it)->Display(0));
		buffer.append("\n");
	}
	buffer.append(doctype);
	buffer.append("\n");
	for (list<PI *>::iterator it = this->prolog_after->begin(); it != this->prolog_after->end(); it++)
	{
		buffer.append((*it)->Display(0));
		buffer.append("\n");
	}
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

list<PI *>* Document::getProlog_before(){
	return prolog_before;
}

string Document::getDoctype(){
	return doctype;
}
