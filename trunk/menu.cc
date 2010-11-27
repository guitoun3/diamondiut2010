#include "jeux.h"
#include "graph.h"
#include "menu.h"

void initMenu(Menu & menu)
{
		
	// Bouton QUIT, coordonnées minimales
	menu.quit.x=0;
	menu.quit.y=0;
	menu.quit.w=150;
	menu.quit.h=60;
	
	// Bouton QUIT, coordonnées maximales
	menu.quit_hover.x=200;
	menu.quit_hover.y=0;
	menu.quit_hover.w=150;
	menu.quit_hover.h=60;
	
	// Bouton PLAY, coordonées minimales
	menu.play.x=0;
	menu.play.y=100;
	menu.play.w=150;
	menu.play.h=60;
	
	// Bouton PLAY, coordonnées maximales
	menu.play_hover.x=200;
	menu.play_hover.y=100;
	menu.play_hover.w=150;
	menu.play_hover.h=60;
	
	// Image du menu
	menu.menu = loadImageWithColorKey("images/button.bmp",0,0,0);

	// Image du fond
	menu.fond = loadImage("images/title.bmp");
	
}

void afficherMenu(SDL_Surface *screen,Menu menu,Plateau plateau, bool & quit)
{	
	
	SDL_Event event;
	
	while(!quit){		
		
		// Affichage du fond
		applySurface(0,0,menu.fond,screen,NULL);
		
		// Affichage des 2 boutons du menu
		applySurface(PLAY_X,PLAY_Y,menu.menu,screen,&menu.play);
		applySurface(QUIT_X,QUIT_Y,menu.menu,screen,&menu.quit);
		
		SDL_PollEvent(&event);
		
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
				quit=true;
		}

		
		// Gestion du RollOver sur les boutons
		if (event.type == SDL_MOUSEMOTION)
		{
				// Rollover sur PLAY
				if ( (event.motion.x > PLAY_X) && (event.motion.x < PLAY_X + PLAY_WIDTH) && (event.motion.y > PLAY_Y) && (event.motion.y < PLAY_Y + PLAY_HEIGHT) )
				{
					applySurface(PLAY_X,PLAY_Y,menu.menu,screen,&menu.play_hover);
				}
				
				// Rollover sur QUIT
				if ( (event.motion.x > QUIT_X) && (event.motion.x < QUIT_X + QUIT_WIDTH) && (event.motion.y > QUIT_Y) && (event.motion.y < QUIT_Y + QUIT_HEIGHT) )
				{
					applySurface(QUIT_X,QUIT_Y,menu.menu,screen,&menu.quit_hover);
				}
		}
		
		// Gestion des clics sur les boutons
		if (event.type == SDL_MOUSEBUTTONUP )
		{
				// Clic sur PLAY
				if ( (event.motion.x > PLAY_X) && (event.motion.x < PLAY_X + PLAY_WIDTH) && (event.motion.y > PLAY_Y) && (event.motion.y < PLAY_Y + PLAY_HEIGHT) )
				{
					// Lancer le jeux
					afficherFenetreJeux(screen,plateau);
					event.type=false; // Permet le retour au menu si on quitte une partie
					initPlateau(plateau);
				}
				
				// Clic sur QUIT
				if ( (event.motion.x > QUIT_X) && (event.motion.x < QUIT_X + QUIT_WIDTH) && (event.motion.y > QUIT_Y) && (event.motion.y < QUIT_Y + QUIT_HEIGHT) )
				{
					quit=true;
				}
		}
		
		SDL_Flip(screen);
	}
	
	// Si on ferme la fenêtre , on libère la mémoire
	if (quit)
	{
		SDL_FreeSurface(menu.menu);
		SDL_FreeSurface(menu.fond);
	}
}
