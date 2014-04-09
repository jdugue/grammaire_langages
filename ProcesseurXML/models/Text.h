#ifndef TEXT_H
#define TEXT_H
#include "Element.h"
#include "Attribut.h"
#include <string>

class Text: public Element
{
public:
    Text(string&);
    ~Text();
    Text(Text& text);
    
    string getContenu();
    
    string toString();

protected:
	string contenu;
};

#endif
