#ligne de compilation finale (avec liens SDL)
CC=g++ -g -I/usr/include/SDL -L/usr/lib -lSDLmain -lSDL -lSDL_image -lSDL_ttf
#ligne de compilation pour le tutorial du site
#CC=g++
OBJECTS= diamant.o plateau.o main.o jeux.o graph.o menu.o

TARGET= diamant

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)



diamant.o : diamant.cc diamant.h
	$(CC) -c diamant.cc

plateau.o : plateau.cc plateau.h diamant.h
	$(CC) -c plateau.cc
	
jeux.o : jeux.cc jeux.h
	$(CC) -c jeux.cc
	
menu.o : menu.cc menu.h
	$(CC) -c menu.cc
	
graph.o : graph.cc graph.h
	$(CC) -c graph.cc
		
main.o : main.cc plateau.h graph.h menu.h
	$(CC) -c main.cc
	

clean :
	rm -f *~ *.o
# DO NOT DELETE
#Genere les 4 lignes de compilation suivantes:
#g++  -c diamant.cc
#g++ -c plateau.cc
#g++  -c main.cc
#g++ diamant.o plateau.o main.o -o diamant
