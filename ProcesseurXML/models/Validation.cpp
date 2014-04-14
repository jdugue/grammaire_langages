#include "Validation.h"
#include <typeinfo> 
#include <utility>
using namespace std;

//map<nom, type> mapElm;
//map<nom, regex> mapType;
      
Validation :: Validation()
{ 
  // types par défaut
  mapType.insert ( make_pair("xsd:string","([^A-Za-z0-9_-])"));
  mapType.insert ( make_pair("xsd:date", "!^(0?\\d|[12]\\d|3[01])-(0?\\d|1[012])-((?:19|20)\\d{2})$!") );
  
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
	string nom;
	string type;
	if (typeid(elm) == typeid(BaliseVide*)){
		    Balise* myBalise = dynamic_cast <Balise*>(elm);
			list<Attribut*>* l = myBalise->getAttributs();
			list<Attribut*>::iterator it = l->begin();
			for (; it != l->end(); it++){
				if ((*it)->getNom() == "name"){
					nom = (*it)->getValeur();
				}
				if ((*it)->getNom() == "type"){
					type = (*it)->getValeur();
				}
			}
			mapElm.insert(make_pair(nom, type));
			// to do : traiter les ref
	}
	else 
		if (typeid(elm) == typeid(BaliseDouble*)){
			BaliseDouble* myBalise = dynamic_cast <BaliseDouble*>(elm);
			if (myBalise->getNom() == "complextype"){
				list<Element*>* l = myBalise->getElements();
				list<Element*>::iterator it = l->begin();
				/*if (typeid(it) == typeid(Balise*)){
					    if ((*it)->getNom() == "sequence"){
							// pausitionner t et faire appel récursif
							// construire l'expression régulière
						}
						else if ((*it)->getNom() == "choice"){
							// pausitionner t et faire appel récursif
							// construire l'expression régulière
						} 
				}
				else error = 1;*/
			}
	} 
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
