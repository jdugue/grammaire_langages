#include "Validation.h" 


//map<nom, type> mapElm;
//map<nom, regex> mapType;
      
Validation :: Validation()
{ 
  // types par défaut
  mapType.insert ( std::pair<string, string>("string","([^A-Za-z0-9_-])"));
  mapType.insert ( std::pair<string, string>("date", "!^(0?\d|[12]\d|3[01])-(0?\d|1[012])-((?:19|20)\d{2})$!") );
  
}

void constructionSchema(Document xsd){

// parcourir les elements du document
 
};
//Fonction parse (element, T, mapT, mapE){
//Si mon element est une balise vide
//Insérer dans mapE : 
//{nom, type}
//Insérer dans mapT : 
//{nom, expression régulière}
		// to do : traiter les références
//Sinon // mon element est une balise double
//	Je parcours la liste de ces element 
//	Si je rencontre : complex type
//		Je parcours la liste des elements de complexe type
//			Si je rencontre choice
//T = 1; // pour choice

//			Sinon, je rencontre : sequence
//			T = 2; // pour sequence
//	parse (element(sequence ou choice), 1 ou 2, mapT, mapE)
//Je construit l’expression régulière de mon element en concaténant 
//les expressions de ces fils avc 1 ou 2, si possible.
//}
  
}

int validationDocument(Document xml, Document xsd){
  // pour chaque element de mon document xml
  // générer la chaine de caractère correspondante
  // tester si la chaine 
  
  // 

  return 0;
}
