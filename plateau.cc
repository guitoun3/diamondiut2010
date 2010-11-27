#include "plateau.h"

// Fonctions

bool isOnScreenArea(SDL_Event event){
	int mouseX,mouseY;
	
	mouseX = event.motion.x;
	mouseY = event.motion.y;
		
	if ( (mouseX >= 0 && mouseX <= (NB_BLOCK_LARGEUR*DIAMANT_WIDTH)) && (mouseY >= 0 && mouseY <= (NB_BLOCK_HAUTEUR*DIAMANT_HEIGHT)) )
		return true;
	else
		return false;
}

void coordDiamantSousSouris(Plateau p, SDL_Event event, int & caseX, int & caseY){
	
	int mouseX,mouseY;

	mouseX = event.motion.x;
	mouseY = event.motion.y;
	
	// Case horizontale
	if (mouseX >= 0 && mouseX <= (NB_BLOCK_LARGEUR*DIAMANT_WIDTH))
	{
		caseX = mouseX / DIAMANT_WIDTH;
	}
	
	// Case verticale
	if (mouseY >= 0 && mouseY <= (NB_BLOCK_HAUTEUR*DIAMANT_HEIGHT)){
		caseY = mouseY / DIAMANT_HEIGHT;
	}
}

void echangerDiamant(Plateau p, SDL_Event event, SDL_Surface *screen, SDL_Surface *sprite){
	int caseClicX,caseClicY;
	int sprite_x,sprite_y;
	int mouseX,mouseY;
	bool clic=false;
	
	SDL_Rect pos;
	
	mouseX = event.motion.x;
	mouseY = event.motion.y;
		
	// 1)Drag And 2)Drop
			
	// 1)Drag
	if (event.type==SDL_MOUSEBUTTONDOWN && isOnScreenArea(event))
	{
		coordDiamantSousSouris(p,event,caseClicX,caseClicY);
		
		sprite_x = (colorDiamant(p.matrice[caseClicY][caseClicX]) - 1 ) * DIAMANT_WIDTH;

		pos.x = sprite_x+5;
		pos.y = sprite_y-5;
		pos.w = DIAMANT_WIDTH-5;
		pos.h = DIAMANT_HEIGHT-5;
		
		clic=true;
		
		applySurface(mouseX,mouseY,sprite,screen,&pos);
	}
	

	
}

void correctionDiamantPlateau(Plateau & p){
	int repeat=0,lastDiamant=0;
	
	// Vérification horizontale
	for(int i=0; i<NB_BLOCK_LARGEUR; i++)
	{
		repeat=0;
		
		for(int j=0; j<NB_BLOCK_HAUTEUR; j++)
		{
			if (lastDiamant==colorDiamant(p.matrice[i][j]))
			{
				repeat++;
				if (repeat==2)
				{
					/*
					 * Si on a 3 diamants collés on modifie le dernier
					 * 
					 * */
					lastDiamant = colorDiamant(p.matrice[i][j]);
					repeat=0;
					do{
						initDiamant(p.matrice[i][j]);
					}while(colorDiamant(p.matrice[i][j]) == lastDiamant);
				}
			}else
			{
				repeat=0;
			}
			lastDiamant = colorDiamant(p.matrice[i][j]);
		}
	}
	
	// Vérification verticale	
	repeat=0;
	lastDiamant=0;
	for(int j=0; j<NB_BLOCK_HAUTEUR; j++)
	{
		repeat=0;
		
		for(int i=0; i<NB_BLOCK_LARGEUR; i++)
		{
			if (lastDiamant==colorDiamant(p.matrice[i][j]))
			{
				repeat++;
				if (repeat==2)
				{
					/*
					 * Si on a 3 diamants collés on modifie le dernier
					 * 
					 * */
					lastDiamant = colorDiamant(p.matrice[i][j]);
					repeat=0;
					do{
						initDiamant(p.matrice[i][j]);
					}while(colorDiamant(p.matrice[i][j]) == lastDiamant);
				}
			}else
			{
				repeat=0;
			}
			lastDiamant = colorDiamant(p.matrice[i][j]);
		}
	}
}

void initPlateau(Plateau & p){
	/*cout << "initPlateau fonctionne, nous allons pouvoir initialiser tous les diamants du plateau" << endl;
	//initialisation du premier diamant
	initDiamant(p.matrice[0][0]);*/
	for(int i=0; i<NB_BLOCK_LARGEUR; i++)
		for(int j=0; j<NB_BLOCK_HAUTEUR; j++)
			initDiamant(p.matrice[i][j]);
	
	correctionDiamantPlateau(p);
}


void afficherPlateau(SDL_Surface *sprite,SDL_Surface *screen,Plateau plateau){
	int diamant_width,diamant_height;
	int pos_x,pos_y;
	int sprite_x,sprite_y=0;
		
	SDL_Rect pos;
	
	// Calcul de la taille des diamants
	diamant_width = SPRITE_WIDTH / (NB_DIAMANTS);
	diamant_height = DIAMANT_HEIGHT;
	
	
	for(int i=0; i<NB_BLOCK_LARGEUR; i++)
	{
		// Calcul de la position horizontale du diamant
		pos_y = i * diamant_height;
		for(int j=0; j<NB_BLOCK_HAUTEUR; j++)
		{
			// Calcul de la position verticale du diamant
			pos_x = j * diamant_width;
			
			// On récupére le diamant sur le sprite
			sprite_x = (colorDiamant(plateau.matrice[i][j]) - 1) * diamant_width;

			pos.x = sprite_x;
			pos.y = sprite_y;
			pos.w = diamant_width;
			pos.h = diamant_height;
			
			applySurface(pos_x,pos_y,sprite,screen,&pos);
		}
	}
	
	/*if (sprite)
		SDL_FreeSurface(sprite);*/
}

