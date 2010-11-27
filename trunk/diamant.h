#ifndef DIAMANT
#define DIAMANT
#include <iostream>
#include <cstdlib>
#include "SDL.h"
#include "SDL_image.h"
#include "graph.h"
using namespace std;
//tous les includes nécéssaires

//Constantes
const int NB_DIAMANTS=8;
const int SPRITE_WIDTH=480;
const int SPRITE_HEIGHT=180;
const int DIAMANT_HEIGHT=60;
const int DIAMANT_WIDTH=SPRITE_WIDTH / (NB_DIAMANTS);

// Définitions des structures
struct Diamant
{
	int color; //attention, il y a peut être mieux que de représenter une couleur que par un entier
	bool isSelected; //indique si le diamant est sélectionné ou pas

};


//Définition des prototypes de fonctions
int randDiamant();
void initDiamant(Diamant & d);
void afficherDiamant(Diamant d);
int colorDiamant(Diamant d);
int colonneDiamant(Diamant d);
int ligneDiamant(Diamant d);

#endif
