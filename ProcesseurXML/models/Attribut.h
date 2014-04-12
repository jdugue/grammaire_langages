#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include <string>
#include <stdio.h>
using namespace std;

class Attribut
{
	public:
		Attribut(const Attribut &); 
		Attribut(char*, char*);
		~Attribut();
		string getNom();
		string getValeur();
		string toString();

	private:
		string valeur;
		string nom;
};


#endif
