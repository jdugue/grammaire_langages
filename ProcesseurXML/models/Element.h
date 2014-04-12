#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <list>
#include <string>
#include "Attribut.h"

using namespace std;

class Element
{
    public:
    Element();
    Element(const Element &);
    virtual string Display(int indent)
    {
    	return string();
    }
    virtual ~Element(){}
};

#endif
