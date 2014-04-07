#include "BaliseDouble.h"

BaliseDouble::BaliseDouble(): Element()
{
    this->lesAttributs = new list<Attribut *>();
    // this->lesElements = (list<Element*>**) calloc(2, sizeof(list<Element*>*));
    this->lesElements = new list<Element *>();
}

BaliseDouble::BaliseDouble(string &nom, list<Element *> *elements, list<Attribut *> *&attributs, string type): Element()
{
    this->lesAttributs = attributs;
    this->lesElements = elements;
    this->nom = nom;
    this->type = type;
}

BaliseDouble::BaliseDouble(BaliseDouble &elemBalise): Element((Element)elemBalise)
{

    this->lesAttributs = elemBalise.lesAttributs;
    this->lesElements = elemBalise.lesElements;
    this->nom = elemBalise.nom;
    this->type = elemBalise.type;
}

list<Element *> *BaliseDouble::getElements()
{
    // cout << "oukay" << endl;
    return lesElements;
}

list<Attribut *> *BaliseDouble::getAttributs()
{
    return lesAttributs;
}

string BaliseDouble::getName()
{
    return nom;
}

string BaliseDouble::getType()
{
    return type;
}

list<Element *> *BaliseDouble::getElementsByName(string name)
{
    list<Element *> *elementsOk = new list<Element *>();
    for (list<Element *>::iterator it = this->lesElements->begin(); it != this->lesElements->end(); it++)
    {
        // if (strcmp((*it)->getName, name) == 0)
        // {
        //     elementsOk->push_back(*it);
        // }
    }
    return elementsOk;
}
BaliseDouble::~BaliseDouble()
{
    //delete lesAttributs;
    //delete nom;
}

string BaliseDouble::toString()
{
    // cout << "ELEMENT_BALISE_TOSTRING" << endl;
    // cout<< "J'ai "<< this->lesElements[0]->size()<<this->lesElements[1]->size()<<" enfants."<<endl;
    string buffer(format("<"));

    char *b = new char [80];
    if (strcmp(this->type, "xml"))
    {
        strcpy(b, this->type);
        strcat(b, ":");
        strcat(b, this->nom);
    }
    else
        strcpy(b, this->nom);
    buffer.append(b);

    for (list<Attribut *>::iterator it = this->lesAttributs->begin(); it != this->lesAttributs->end(); it++)
    {
        buffer.append(" ");
        buffer.append((*it)->toString());
    }
    buffer.append(">");

    //Boucle pour les elements
    for (list<Element *>::iterator it = this->lesElements->begin(); it != this->lesElements->end(); it++)
    {
        buffer.append("\n");
        moarIndent();
        buffer.append(format((*it)->toString()));
        lessIndent();
    }

    buffer.append("\n");
    buffer.append(format("</"));
    buffer.append(b);
    buffer.append(">");

    char *cstr = new char[buffer.length() + 1];
    strcpy(cstr, buffer.c_str());
    return cstr;
}

void BaliseDouble::addElement(list<Element*>* elem){
    this->lesElements->insert(this->lesElements->begin(),elem->begin(),elem->end());
}