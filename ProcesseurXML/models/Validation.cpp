#include "Validation.h"
#include <typeinfo> 
using namespace std;

//map<nom, type> mapElm;
//map<nom, regex> mapType;
      
Validation :: Validation()
{ 
  // types par défaut
  mapType.insert ( std::pair<string, string>("string","([^A-Za-z0-9_-])"));
  mapType.insert ( std::pair<string, string>("date", "!^(0?\\d|[12]\\d|3[01])-(0?\\d|1[012])-((?:19|20)\\d{2})$!") );
  
}

int Validation::constructionSchema(Document xsd){
	int error = 0;
	list<Element *>* liste = xsd.getElems();
	list<Element *>::iterator it = liste->begin();

	for (;(it != liste->end()) && (error == 0); it++){
		if ((typeid(*it) == typeid(BaliseDouble*)) || (typeid(*it) == typeid(BaliseVide*)) ){
			error = constructionExpression(*it);
		}
	}
}

int Validation::constructionExpression(Element* elm){
	int error = 0;
	if (typeid(elm) == typeid(BaliseVide*)){
		    Balise* myBalise = dynamic_cast <Balise*>(elm);
			list<Attribut*>* l = myBalise->getAttributs();
			list<Attribut*>::iterator it = l->begin();
			for (; it != l->end(); it++){
				if ((*it)->getNom() == "type"){
					
				}
			}
	}
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
	return error;
}


int Validation::validationDocument(Document xml, Document xsd){
  int error = 0;
  // pour chaque element de mon document xml
  // générer la chaine de caractère correspondante
  // tester si la chaine  
  // 
  

  return error;
}
