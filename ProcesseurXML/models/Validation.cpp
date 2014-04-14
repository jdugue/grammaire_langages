#include "Validation.h" 
#include <typeinfo>
using namespace std;

//map<nom, type> mapElm;
//map<nom, regex> mapType;
      
Validation :: Validation()
{ 
  // types par défaut
  mapType.insert ( std::pair<string, string>("string","([^A-Za-z0-9_-])"));
  mapType.insert ( std::pair<string, string>("date","([[:digit:]]{4})-([[:digit:]]{2})-([[:digit:]]{2})") );
}

void constructionSchema(Document xsd){
	list<Element *>* liste = xsd.getElems();
	list<Element *>::iterator it = liste->begin();
	// Pour tout les balise element
	for (;it != liste->end(); it++){
	//	if (l'element est une balise element
	//constructionExpression(it);
		if (typeid(*it) == typeid(BaliseDouble)){
		}
	}
}

int constructionExpression(Element* elm){
//if mon element est une balise vide 
	//if type = String ou date
	   //mapElm.insert(pair{nom, type});
	//if type est une occurence To do : réfléchir à  la construction de l'expression
	   // puis insérer dans mapType{nom, expression régulière}
 
//Sinon (mon element est une balise double)
//	Je parcours la liste de ces element 
//	Si je rencontre : complex type
//		Je parcours la liste des elements de complexe type
//			Si je rencontre choice
//          T = 1;

//			Sinon (je rencontre : sequence)
//			T = 2;
//	        constructionExpression(element(sequence ou choice), T)
//   Je parcour les fils à le recherche de leur expression régulière;  
//    Je construit l’expression régulière de mon element en concaténant 
//  les expressions de ces fils avc 1 ou 2, si possible.
	return 0;
}


int validationDocument(Document xml, Document xsd){
  // pour chaque element de mon document xml
  // générer la chaine de caractère correspondante
  // tester si la chaine  
  // 
  

  return 0;
}
