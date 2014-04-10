#include "commun.h"
#include <iostream>
#include <cstring>
#include "models/Document.h"

using namespace std;

int xmlparse(Document**);

int main(void)
{
		Document * doc;
   int retour = xmlparse(&doc);
   if (!retour)
   {
      cout<<"Entrée standard reconnue"<<endl;
   }
   else
   {
      cout<<"Entrée standard non reconnue"<<endl;
   }
   return 1;
}
