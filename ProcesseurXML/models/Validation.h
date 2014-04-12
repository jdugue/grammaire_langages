#include<string.h>
#include"Element.h"
#include"Commentaire.h"
#include"Text.h"
#include"Balise.h"
#include"PI.h"
#include"BaliseVide.h"
#include"BaliseDouble.h"
#include"Attribut.h"
#include"Document.h"

#include<map>

typedef string nom;
typedef string type;
typedef string regex;

class Validation
{
  public:
      Validation();
      
  private:
      map<nom, type> mapElm;
      map<nom, regex> mapType;
      int validationDocument(Document xml, Document xsd);
      void constructionSchema(Document xsd);
	  int constructionExpression(Element* elm);
      
};
