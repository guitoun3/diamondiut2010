#include "diamant.h"


int randDiamant(){
	return rand()%(NB_DIAMANTS) +1;
}

void initDiamant(Diamant & d){
	d.color = randDiamant();
	d.isSelected = false;
}

void afficherDiamant(Diamant d){
	cout << d.color;
}

int colorDiamant(Diamant d){
	return d.color;
}

int colonneDiamant(Diamant d){
	
}

int ligneDiamant(Diamant d){
	return 0;
}
