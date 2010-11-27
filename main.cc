#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iostream>

#include "main.h"
#include "graph.h"
#include "menu.h"
#include "jeux.h"
#include "plateau.h"
#include "diamant.h"

using namespace std;


int main( int argc, char* args[] )
{
	bool quit=false;
	
	SDL_Surface *screen;
	SDL_Event event;
	
	Menu menu;
	Plateau plateau;
	
	// Initialisation de la SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
		
	initMenu(menu);
	
	initPlateau(plateau);
	
	/*int saisit;
	
	do{
		cin >> saisit;
		initPlateau(plateau);
		afficherPlateau(plateau);
	}while(saisit!=0);*/
	

		
	while (!quit)
	{

		afficherMenu(screen,menu,plateau,quit);
		
		
		SDL_Flip(screen);
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
				quit=true;
		}
	}
	
	SDL_FreeSurface(screen);
	
	SDL_Quit();
	
	return EXIT_SUCCESS;    
}
