#include "jeux.h"
#include "graph.h"



void afficherFenetreJeux(SDL_Surface *screen,Plateau plateau){
	
	bool quit=false;
	
	SDL_Event event;
	SDL_Surface *sprite;
	SDL_Surface *fond_jeux;
	
	sprite = loadImageWithColorKey("images/pieces.bmp",0,255,255);
	fond_jeux = loadImage("images/fond.bmp");
	
		
	while(!quit)
	{
		// Affichage du fond
		applySurface(0,0,fond_jeux,screen,NULL);
		
		afficherPlateau(sprite, screen, plateau);
				
		echangerDiamant(plateau, event, screen, sprite);
		
		
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
				quit=true;
		}
		
		SDL_Flip(screen);
	}

	SDL_FreeSurface(sprite);
	SDL_FreeSurface(fond_jeux);
}
