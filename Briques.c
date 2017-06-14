#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include "Briques.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 780


void initbriques(SDL_Rect2 briques[32]){
//BUT: Remplir un tableau avec les coordonnées des briques
//ENTREE: Tableau de briques vide
//SORTIE: Tableau de briques rempli avec les bonnes coordonnées
int i,x,y;
x=0;
y=24;

for(i=0;i<32;i++){
  briques[i].brique.x=x;
  briques[i].brique.y=y;
  briques[i].brique.w=64;
  briques[i].brique.h=24;
  briques[i].destroyed=False;
  x=x+64;
  if(i==15){
        y=y+24;
        x=0;
  }

}























}
