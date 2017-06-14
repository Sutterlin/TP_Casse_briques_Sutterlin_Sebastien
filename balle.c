#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include "balle.h"


#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 780


void deplacementBalle(game *MyGame,gameState state, ball *ball, SDL_Rect paddle, SDL_Rect2 briques[32]){
//BUT:Gérer le déplacement de la balle et ses collisions
//ENTREE: La balle, la raquette et le tableau contenant les briques.
//SORTIE: Les coordonnées de la balle et sa direction mises à jour.
int i;


//on définit le déplacement de la balle en diagonale, en fonction de sa direction.


if (ball->direction==1){
        ball->x=ball->x+3;
ball->y=ball->y+3;
}


if (ball->direction==2){
        ball->x=ball->x+3;
ball->y=ball->y-3;
}


if (ball->direction==3){
        ball->x=ball->x-3;
ball->y=ball->y+3;
}


if (ball->direction==4){
        ball->x=ball->x-3;
ball->y=ball->y-3;
}

if (ball->x>SCREEN_WIDTH-24){
    ball->x=ball->x-3;

   if( ball->direction==1){
    ball->direction=3;
   }

   if( ball->direction==2){
    ball->direction=4;
   }

}

//on définit les rebonds de la balle.

if (ball->x<0){ //rebond mur gauche
    ball->x=ball->x+3;

   if( ball->direction==3){
    ball->direction=1;
   }

   if( ball->direction==4){
    ball->direction=2;
   }

}


//rebond plafond
if (ball->y<0){
    ball->y=ball->y+3;

   if( ball->direction==2){
    ball->direction=1;
   }

   if( ball->direction==4){
    ball->direction=3;
   }

}
//retour au milieu si la raquette rate la balle
if (ball->y>SCREEN_HEIGHT){
    ball->x=SCREEN_WIDTH/2;
    ball->y=SCREEN_HEIGHT/2;




}

//rebond sur la raquette
if (((ball->y+24)>paddle.y)&&(ball->y<(SCREEN_HEIGHT+paddle.h))&&(ball->x>paddle.x)&&(ball->x<(paddle.x+paddle.w))){
    ball->y=ball->y-3;

   if( ball->direction==1){
    ball->direction=2;
   }

   if( ball->direction==3){
    ball->direction=4;

}




}
//collision avec les blocs
for(i=0;i<32;i++){
//si le haut ou le bas de la balle touche un bloc, on change de direction
   if((((ball->x+12)>=briques[i].brique.x)&&(ball->y>=briques[i].brique.y)&&((ball->x+12)<=(briques[i].brique.x+briques[i].brique.w))&&(ball->y<=(briques[i].brique.y+briques[i].brique.h))&&(briques[i].destroyed==False))||(((ball->x+12)>=briques[i].brique.x)&&((ball->y+24)>=briques[i].brique.y)&&((ball->x+12)<=(briques[i].brique.x+briques[i].brique.w))&&((ball->y+24)<=(briques[i].brique.y+briques[i].brique.h))&&(briques[i].destroyed==False))){

      switch(ball->direction){

      case 1:
          ball->direction=2;
      break;

      case 2:
          ball->direction=1;
      break;

      case 3:
          ball->direction=4;
      break;

      case 4:
          ball->direction=3;
      break;


      }
//on détruit le bloc en activant le booléen du bloc correspondant. Si true, le bloc disparait et la balle ne rebondit plus
briques[i].destroyed=True;









    //si les côtés de la balle touchent un bloc, on change de direction                                                                                                                  }

   if((((ball->x+24)>=briques[i].brique.x)&&((ball->y+12)>=briques[i].brique.y)&&((ball->x+24)<=(briques[i].brique.x+briques[i].brique.w))&&((ball->y+12)<=(briques[i].brique.y+briques[i].brique.h))&&(briques[i].destroyed==False))||(((ball->x)>=briques[i].brique.x)&&((ball->y+12)>=briques[i].brique.y)&&((ball->x)<=(briques[i].brique.x+briques[i].brique.w))&&((ball->y+12)<=(briques[i].brique.y+briques[i].brique.h))&&(briques[i].destroyed==False))){

      switch(ball->direction){

      case 1:
          ball->direction=3;
      break;

      case 2:
          ball->direction=4;
      break;

      case 3:
          ball->direction=1;
      break;

      case 4:
          ball->direction=2;
      break;


      }

briques[i].destroyed=True;









                                                                                                                      }





}

}





}
