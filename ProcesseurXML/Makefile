COMP = g++ -I ./models/
EDL = g++
ECHO = echo
RM = rm

ALL = all
TEST = test
COMMUN = commun
EFFACE = clean
LIBS = $(PATH_LIB)

SRC =   $(wildcard ./*.cpp) $(wildcard ./models/*.cpp)
OBJETS =   $(SRC:.o=.cpp)

${ALL}:${COMMUN}
${COMMUN}:${OBJETS} xml.l xml.y
	flex -P xml xml.l
	bison -p xml --debug --verbose --defines=xml.tab.h xml.y
	${COMP} -c xml.tab.c
	${COMP} -c lex.xml.c
	#${EDL} -std=c++11 -g -o xmltool ${OBJETS} xml.tab.c lex.xml.c
	${EDL} -std=c++0x -g -o xmltool ${OBJETS} xml.tab.c lex.xml.c
	touch commun
${EFFACE}:
	${RM} -rf xml.tab.c lex.xml.c xml.tab.h xml.output xmltool commun
${TEST}:
	cd Tests; ./mktest.sh

%.o:%.cpp 
	${COMP} -c $<

