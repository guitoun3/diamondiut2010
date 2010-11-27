#ifndef MENU
#define MENU
#include <iostream>
#include <cstdlib>
#include "SDL.h"
#include "SDL_image.h"
#include "main.h"
#include "plateau.h"
using namespace std;

// Constantes
const int PLAY_Y=(SCREEN_HEIGHT/2) - 140; 	// Pos. verticale du bouton play
const int PLAY_X=(SCREEN_WIDTH/2) - 75; 	// Pos. horizontale du bouton play
const int QUIT_Y=(SCREEN_HEIGHT/2) + 70; 	// Pos. verticale du bouton quit
const int QUIT_X=(SCREEN_WIDTH/2) - 75; 	// Pos. horizontale du bouton quit
const int PLAY_WIDTH=150;					// Largeur bouton play
const int PLAY_HEIGHT=60;					// Hauteur bouton play
const int QUIT_WIDTH=150;					// Largeur bouton quit
const int QUIT_HEIGHT=60;					// Hauteur bouton quit

// Structures

struct Menu{
	SDL_Surface *menu;		// Image du sprite du menu
	SDL_Surface *fond; 		// Image du fond
	SDL_Rect quit;			// Bouton QUIT
	SDL_Rect quit_hover; 	// Bouton QUIT HOVER
	SDL_Rect play; 			// Bouton PLAY
	SDL_Rect play_hover; 	// Bouton PLAY HOVER
};

// -- menu --------------------------------------
// Affichage du menu d'accueil
// Affichage du bouton Jouer / Quitter
void initMenu(Menu & menu);
void afficherMenu(SDL_Surface *screen,Menu menu,Plateau plateau,bool & quit);

#endif
