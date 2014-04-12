#include "commun.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include "models/Document.h"

using namespace std;

int xmlparse(Document**);    
    
int main(int argc, char **argv) 
{
	extern FILE *xmlin;
	Document *doc;
	
	if (argc < 2)
	{
		fprintf(stderr,"No argument given\n");
		fprintf(stderr,"Available commands are:\n");
		fprintf(stderr,"../xmltool -p file.xml : parse and display the xml file\n");
		fprintf(stderr,"../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result\n");
		fprintf(stderr,"../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl\n");
		fprintf(stderr,"../xmltool -h : displays this help\n");
		return 1;
	}
	else if (strcmp(argv[1],"-h") == 0)
	{
		fprintf(stderr,"Available commands are:\n");
		fprintf(stderr,"../xmltool -p file.xml : parse and display the xml file\n");
		fprintf(stderr,"../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result\n");
		fprintf(stderr,"../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl\n");
		fprintf(stderr,"../xmltool -h : displays this help\n");
		return 1;
	}
	else if (strcmp(argv[1],"-p") == 0)
	{
		if (argc < 3)
		{
			fprintf(stderr,"You must provide an argument to the command -p\n");
			return 1;
		}
		else
		{
			int retour;
			FILE *fid = fopen(argv[2], "r");
			if (fid == NULL)
			{
				fprintf(stderr,"Unable to open ");
				fprintf(stderr,argv[2]);
				return 1;
			}
			xmlin = fid;
			retour = xmlparse(&doc);
			if (doc != NULL)
			{
				if (retour != 1)
				{
					cout << doc->Display() << endl;
				}
			}
			fclose(fid);
		}
	}
	else if (strcmp(argv[1],"-t") == 0)
	{
		if (argc < 4)
		{
			fprintf(stderr,"You must provide two arguments to the command -t: an xml file and an xsl file\n");
			return 1;
		}
	}
	else if (strcmp(argv[1],"-v") == 0)
	{
		if (argc < 4)
		{
			fprintf(stderr,"You must provide two arguments to the command -v: an xml file and an xsd file\n");
			return 1;
		}
	}
}
