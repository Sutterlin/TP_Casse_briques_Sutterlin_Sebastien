#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include "raquette.h"


#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 780


void handleEvents(gameState *state, SDL_Rect *paddle){
//BUT: Déplacer la raquette quand on presse les touches
//Entrée: la raquette
//Sortie: la raquette déplacée

    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
              state->g_bRunning=0;break;
        case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                            {
                                case SDLK_LEFT:state->left=1;state->right=0;paddle->x=paddle->x-20; //déplacement si on appuie sur gauche
                                if (paddle->x<-10){
                                    paddle->x=paddle->x+20; //on fait en sorte que la raquette ne sorte pas de l'écran
                                }  break;
                                case SDLK_RIGHT: state->right=1;state->left=0;paddle->x=paddle->x+20; //droite
                                 if (paddle->x>(SCREEN_WIDTH-paddle->w)){
                                    paddle->x=paddle->x-20;
                                }
                                  break;
                                case SDLK_UP:    ; break;
                                case SDLK_DOWN:  ; break;
                                case SDLK_d:  break;
                                case SDLK_q:  break;
                            }
                            break;

        case SDL_KEYUP:;break;

        default:break;

        }
    }


}

