#ifndef ATTRIBUT_H
#define ATTRIBUT_H

#include <string>
#include <stdio.h>
using namespace std;

class Attribut
{
	public:
		Attribut(const Attribut &);        //constructeur de copie   
		Attribut(string, string);
		string getValeur();
		string getNom();
		~Attribut();
		string toString();

		/* data */
	private:
		string valeur;
		string nom;
};


#endif