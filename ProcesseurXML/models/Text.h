#ifndef TEXT_H
#define TEXT_H
#include "Element.h"
#include "Attribut.h"
#include <list>
#include <string>

class Text: public Element
{
public:
    Text(string&, list<Attribut*>*);
    ~Text();
    Text(Text& text);
    
    string getContenu();
    
    string toString();

protected:
	string contenu;
};

#endif
