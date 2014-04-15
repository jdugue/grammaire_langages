#include "Validation.h"
#include <typeinfo> 
#include <utility>
#include <regex.h>
#include <sstream>
using namespace std;

static bool regex_match(string reg, string stringTest)
{
	regex_t regex;
	int reti;
	char msgbuf[100];

	/* Compile regular expression */
	reti = regcomp(&regex, reg.c_str(), REG_EXTENDED);
	if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }
	/* Execute regular expression */
	reti = regexec(&regex, stringTest.c_str(), 0, NULL, 0);
	if( !reti ){
		return true;
	}
	else if( reti == REG_NOMATCH ){
		return false;
	}
	else{
		regerror(reti, &regex, msgbuf, sizeof(msgbuf));
		fprintf(stderr, "Regex match failed: %s\n", msgbuf);
		exit(1);
	}
} 

static string RemplacerRefs(string nom, map<string, string>& mapRegex)
{
	string::size_type posBegin = mapRegex[nom].find_first_of("@");
	if (posBegin != string::npos) {

		string regex = "";
		vector<string> ref;
		//On split la chaine selon "@"
		string::size_type posEnd = mapRegex[nom].find("@", posBegin);
		while(posEnd != string::npos) {
			string refCourante = mapRegex[nom].substr(posBegin+1, posEnd-posBegin-1);
			ref.push_back(refCourante);
			posBegin = posEnd;
			posEnd = mapRegex[nom].find("@", posBegin+1);
		}

		for(int i = 0 ; i < ref.size() ; i++) {
			if (mapRegex.count(ref[i]) > 0) {
				regex = RemplacerRefs(ref[i], mapRegex);
				mapRegex[nom].replace(mapRegex[nom].find_first_of("@"), ref[i].size()+2, "("+regex+")");
			} else {
				//inquiétant ?
			}
		}
	}

	return mapRegex[nom];
}

Validation::Validation(Document * docxml, Document * docxsd)
{ 
	Element* root = docxsd->getElems()->front();
	constructionExpression(root,mapRegex);

	//Suppression des ref et remplacement par ce a quoi elles font reference

	for(map<string, string>::iterator it=mapRegex.begin() ; it!=mapRegex.end() ; ++it)
	{
		RemplacerRefs(it->first, mapRegex);
	}

	isValid = ValiderXML(docxml->getElems()->front(), mapRegex);
}

bool Validation::IsValid()
{
	return isValid;
}

string Validation::constructionExpression(Element* elm,mRegex& mapRegex)
{

	Balise * myBalise = dynamic_cast<Balise*>(elm);
	string reg = "";
	if (myBalise)
	{
		if (Attribut * att = myBalise->getAttribut("name"))
		{
			reg += "<" + att->getValeur() + ">";
		}
		if (myBalise->getNom() == "complexType")
		{
			if (myBalise->getElements())
			{
				for (list<Element *>::iterator it = myBalise->getElements()->begin(); it != myBalise->getElements()->end(); it++)
				{
					reg += constructionExpression(*it,mapRegex);
				}
			}
		}
		else if (Attribut * att = myBalise->getAttribut("ref"))
		{
			string ref = att->getValeur();
			reg += "@" + ref + "@";
			Attribut * minOccurs = myBalise->getAttribut("minOccurs");
			Attribut * maxOccurs = myBalise->getAttribut("maxOccurs");
			if (minOccurs && maxOccurs)
			{
				reg += "{" + minOccurs->getValeur() + "," + maxOccurs->getValeur() + "}";
			}
			else if (minOccurs)
			{
				reg += "{" + minOccurs->getValeur() + "," + "}";
			}
			else if (maxOccurs)
			{
				reg += "{1," + maxOccurs->getValeur() + "}";
			}
		}
		else if (myBalise->getNom() == "sequence")
		{
			
			if (myBalise->getElements())
			{
				reg += "(";
				for (list<Element *>::iterator it = myBalise->getElements()->begin(); it != myBalise->getElements()->end(); it++)
				{
					reg += constructionExpression(*it,mapRegex);
				}
				reg += ")";
			}
			
		}
		else if (myBalise->getNom() == "choice")
		{
			
				if (myBalise->getElements())
				{
					reg += "(";
					for (list<Element *>::iterator it = myBalise->getElements()->begin(); it != myBalise->getElements()->end(); it++)
					{
						reg += constructionExpression(*it,mapRegex);
						reg += "|";
					}
					reg.erase(reg.size()-1);
					reg += ")";
				}
				
		}
		else
		{
					// TESTER LA DATE
			reg += "[^<&]*";
			if (myBalise->getElements())
			{

				for (list<Element *>::iterator it = myBalise->getElements()->begin(); it != myBalise->getElements()->end(); it++)
				{
					reg += constructionExpression(*it,mapRegex);
				}
			}
		}
		if (Attribut * att = myBalise->getAttribut("name"))
		{
			reg += "</" + att->getValeur() + ">";
			mapRegex[att->getValeur()]=reg;
		}
	}
	return reg;
}

bool Validation::ValiderXML(Element* elt, map<string,string>& mapreg) const
{
	string stringTest = elt->DisplayMyChildrenButNotMyGrandchildren(true);
	//trouver si le noeud à une regex associée dans mapreg
	map<string,string>::iterator it;
	
	Balise* myBalise = dynamic_cast<Balise*>(elt);
	string baliseName = myBalise->getNom();

	it=mapreg.find(baliseName);
	if (it==mapreg.end())
	{
		return false;
	}
	else
	{
		string reg = mapreg[baliseName];
		if(regex_match(reg, stringTest))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}