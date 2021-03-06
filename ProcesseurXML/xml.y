%{
#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#include "commun.h"
#include "models/Document.h"
#include "models/Attribut.h"
#include "models/PI.h"
#include "models/Text.h"
#include "models/Element.h"
#include "models/BaliseDouble.h"
#include "models/BaliseVide.h"
#include "models/Commentaire.h"

extern char xmltext[];

int xmllex(void);  

void xmlerror(Document ** doc, const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char * s;
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
%type <lelem> elements content
%type <elem> element
%type <pi> pi
%type <lpi> entete
%type <latts> atts
%type <att> att
%type <text> cdata
%type <s> doctype valeurs 

%parse-param {Document ** doc}
//%error-verbose

%%

document
 : entete doctype entete elements {*doc=new Document($1,$2,$3,$4);}
 
elements
 : elements element {$$=$1;$$->push_back($2);}
 |/*vide*/ {$$ = new list<Element*>();}
 ;
element
 : INF NOM atts SUP content 
   INF SLASH NOM SUP  { 
		 if (strcmp($2,$8)!=0) 
		 {
		 	fprintf(stderr,"Non matching element names %s and %s\n",$2,$8);
		 } 
		 $$=new BaliseDouble($2,$5,$3);
   }
 |INF NOM COLON NOM atts SUP content 
   INF SLASH NOM COLON NOM SUP { 
   	if (strcmp($2,$10)!=0)
   	{
   		fprintf(stderr,"Non matching element namespaces %s and %s\n",$2,$10);
   	}
   	if (strcmp($4,$12)!=0) 
   	{
   		fprintf(stderr,"Non matching element names %s and %s\n",$4,$12);
   	}
   	$$=new BaliseDouble($4,$7,$5,$2);
   }
 | INF NOM atts SLASH SUP { $$=new BaliseVide($2,$3);}
 | INF NOM COLON NOM atts SLASH SUP  { $$=new BaliseVide($4,$5,$2);}       
 ;
content
 : content element {$$=$1;$$->push_back($2);}  
 | content cdata {$$=$1;$$->push_back($2);}  
 | content DONNEES {$$=$1;$$->push_back(new Text($2,1));}  
 | content COMMENT  {$$=$1;$$->push_back(new Commentaire($2));}        
 | /* vide */    {$$ = new list<Element*>();}          
 ;
entete
 :entete pi   	{$$=$1;$$->push_back($2);}
 | /* vide */   { $$ = new list<PI*>();}  
 ;

doctype
:DOCTYPE NOM NOM valeurs SUP{char str[1000];
					strcpy(str,"<!DOCTYPE ");
					strcat(str,$2);
					strcat(str," ");
					strcat(str,$3);
					strcat(str," ");
					strcat(str,$4);
					strcat(str,">");
					$$=str;}
|/* vide */ {char str[10];
					strcpy(str,"");
					$$ = str;}
;     
valeurs 
 : valeurs VALEUR {$$=$1; strcat($$,"\""); strcat($$,$2); strcat($$,"\"");}
 |/* vide */ {$$ = new char[1000];}
 ;

pi
 :INFSPECIAL NOM atts SUPSPECIAL {$$ = new PI($2,$3);}
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
 : CDATABEGIN CDATAEND {$$= new Text($2,2);}
 ;

