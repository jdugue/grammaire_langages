#ifndef TEXT_H
#define TEXT_H
#include "Element.h"

class Text: public Element
{
	public:
    Text();
    Text(char*, int);
    ~Text();
    Text(Text& text);
    string Display(int indent);
    virtual string DisplayNoAtts();
    int getType();
    string getContenu();

	protected:
		int type; // 1 pour du texte simple, 2 pour du CDATA
		string contenu;
};

#endif
