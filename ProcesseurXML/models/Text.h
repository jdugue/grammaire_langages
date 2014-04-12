#ifndef TEXT_H
#define TEXT_H
#include "Element.h"
#include "Attribut.h"
#include <string>

class Text: public Element
{
	public:
    Text();
    Text(char*);
    ~Text();
    Text(Text& text);

	protected:
		string contenu;
};

#endif
