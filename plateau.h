#ifndef PLATEAU
#define PLATEAU
#include <iostream>


#include "diamant.h"

using namespace std;

// Constants

const int NB_BLOCK_LARGEUR = 8;
const int NB_BLOCK_HAUTEUR = 8;

// Structures

struct Plateau
{
  Diamant matrice[NB_BLOCK_HAUTEUR][NB_BLOCK_LARGEUR];
};

//Définition des prototypes de fonctions
void correctionDiamantPlateau(Plateau & p);
void initPlateau(Plateau & p);
void afficherPlateau(SDL_Surface *sprite,SDL_Surface *screen,Plateau plateau);
bool isOnScreenArea(SDL_Event event);
void coordDiamantSousSouris(Plateau p, SDL_Event event, int & caseX, int & caseY);
void echangerDiamant(Plateau p, SDL_Event event, SDL_Surface *screen, SDL_Surface *sprite);
#endif
