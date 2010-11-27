#ifndef JEUX
#define JEUX
#include <iostream>
#include <cstdlib>
#include "SDL.h"
#include "SDL_image.h"
#include "main.h"
#include "plateau.h"
using namespace std;

// Constantes
const int GAME_WIDTH=487;					// Largeur de la zone de jeux
const int GAME_HEIGHT=500;					// Hauteur de la zone de jeux

// Structures



// -- menu --------------------------------------
// Affichage du menu d'accueil
// Affichage du bouton Jouer / Quitter
void afficherFenetreJeux(SDL_Surface *screen,Plateau plateau);

#endif
