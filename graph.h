#ifndef GRAPH
#define GRAPH
#include <iostream>
#include <cstdlib>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

// Constantes

// -- loadImage ---------------------------------
// chargement d'une image
// ----------------------------------------------
SDL_Surface * loadImage(string filename);

// -- loadImageWithColorKey ---------------------
// chargement d'une image
// * paramètres entrées :
// - "filename" : nom de l'image
// - "r,g,b"    : couleur de la ColorKey; cette
//   couleur devient transparente !
// * paramètre de sortie : SDL_Surface contenant
//   l'image.
// ----------------------------------------------
SDL_Surface * loadImageWithColorKey(string filename, int r, int g, int b);

// -- applySurface ------------------------------
// c'est le copier-coller d'une surface sur une
// autre : on colle le rectangle "clip" de "source"
// sur "destination" à partir de "x,y"
// ----------------------------------------------
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);




#endif
