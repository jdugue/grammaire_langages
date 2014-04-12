#ifndef USEFULLFUNCS_H
#define USEFULLFUNCS_H

#include <string>

using namespace std;

static void addTabs(string& str, int nbTabs)
{
	for (int i = 0 ; i < nbTabs ; ++i)
	{
		str.append("  ");
	}
}

#endif // USEFULLFUNCS_H
