#ifndef TEXT_H
#define TEXT_H
#include "Element.h"

class Text: public Element
{
	public:
    Text();
    Text(char*);
    ~Text();
    Text(Text& text);
    string Display(int indent);

	protected:
		string contenu;
};

#endif
