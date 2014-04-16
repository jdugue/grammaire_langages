#include <string>
#include "Element.h"
#include "Commentaire.h"
#include "Text.h"
#include "Balise.h"
#include "PI.h"
#include "BaliseVide.h"
#include "BaliseDouble.h"
#include "Attribut.h"
#include "Document.h"
#include <regex.h>

#include <map>

typedef string nom;
typedef string regex;
typedef map<nom,regex> mRegex;

class Validation
{
  public:
  	Validation(Document * docxml, Document * docxsd);
  	bool IsValid();
      
  private:
  	mRegex mapRegex;
  	bool isValid;
  	//int validationDocument(Document xml, Document xsd);
  	//int constructionSchema(Document xsd);
	string constructionExpression(Element* elm,mRegex& mapRegex);
	bool ValiderXML(Element* elt, map<string,string>& mapreg);
};
