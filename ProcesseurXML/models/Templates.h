#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
#include <list>
#include <map>
#include "BaliseDouble.h"

using namespace std;

class Templates
{
	public:
		Templates(BaliseDouble*);
		~Templates();
		string Display();
		
	private:
  		map<string, map<string,BaliseDouble*> > templates;
};

#endif
