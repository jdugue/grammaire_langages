%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#include "commun.h"
#include "Document.h"
#include "Attribut.h"
#include "PI.h"
#include "Text.h"
#include "Element.h"


extern char xmltext[];

int xmllex(void);  

void xmlerror(const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char * s;
   Document* doc;
   Element* elem;
   list<Element*>* lelem;
   PI* pi;
   list<PI*>* lpi;
   list<Attribut*>* latts;
   Attribut* att;
   Text* text;
	
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND 
%type <doc> document
%type <lelem> elements content
%type <elem> element
%type <pi> pi
%type <lpi> entete
%type <latts> atts valeurs 
%type <att> att
%type <text> cdata
%type <s> doctype


%%

document
 : entete doctype elements { $$=new Document($1,$2,$3);}
 ;
elements
 : elements element {$$=$1;$$->push_back($2);}
 |/*vide*/ {$$ = new list<Element*>();}
 ;
element
 : INF NOM atts SUP content 
   INF SLASH NOM SUP  { $$=new BaliseDouble($2,$3,$5);}
 |INF NOM COLON NOM atts SUP content 
   INF SLASH NOM SUP { $$=new BaliseDouble($4,$5,$7,$2);}
 | INF NOM atts SLASH SUP { $$=new BaliseVide($2,$3);}
 | INF NOM COLON NOM atts SLASH SUP  { $$=new BaliseVide($4,$5,$2);}       
 ;
content
 : content element {$$=$1;$$->push_back($2);}  
 | content cdata {$$=$1;$$->push_back($2);}  
 | content DONNEES {$$=$1;$$->push_back(new Text($2));}  
 | content COMMENT  {$$=$1;$$->push_back(new Commentaire($2));}        
 | /* vide */    {$$ = new list<Element*>();}          
 ;
entete
 :entete pi   { $$ = new list<PI>();}
 | /* vide */     
 ;

doctype
:DOCTYPE NOM NOM valeurs SUP{ char str[1000];
					strcpy(str,$3);
					strcat(str,$4);
					strcat(str,">");
					$$=str;}
|/* vide */
;     
valeurs 
 : valeurs VALEUR {$$=$1;$$->push_back($2);}
 |/* vide */ {$$ = new list<Attribut*>();}
 ;
pi
 : INFSPECIAL NOM atts SUPSPECIAL {$$ = new PI($2,$3);}
 |INFSPECIAL NOM COLON NOM atts SUPSPECIAL {$$ = new PI($4,$5,$2);}
 ;
atts
 : atts att {$$=$1;$$->push_back($2);}
 |/* vide */    {$$ = new list<Attribut*>();}
 ;
att
 : NOM EGAL VALEUR {$$ = new Attribut($1,$3);}
 | NOM COLON NOM EGAL VALEUR { $$ = new Attribut($3,$5);}
 ;
cdata
 : CDATABEGIN CDATAEND {$$= new Text($2);}
 ;

