#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD

=======
#include <SDL.h>
>>>>>>> dd31b47dbd4ed4f1d77e2e7f410d04d72e44d450
#include <SDL2/SDL_image.h>
#include <time.h>
#include "main.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 780


//Option de build dans les linker setting mettre les libSDL2main.a libSDL2.dll.a
//Dans search directory
//Option de build compiler mettre les include
//Option de build linker mettre les lib

//mettre dans build linker -lmingw32





int main(int argc, char *argv[])
{

     game myGame;
     gameState state;
    // double *paddlex=(15);
    // double *paddley=(SCREEN_HEIGHT-10);
     SDL_Rect paddle; //on déclare une instance de raquette
     ball ball;        //pareil pour la balle
     int i;
     ball.x=SCREEN_WIDTH-50;   //les coordonnées de la balle, on lui attribue ses valeurs initiales
     ball.y=SCREEN_HEIGHT/2;
     ball.direction=2;         //la direction initiale de la balle
     paddle.x=15;              //coordonnées initiales de la raquette
     paddle.y=(SCREEN_HEIGHT-10);
     paddle.w=80; //largeur de la raquette
     SDL_Rect2 briques[32];  //tableau de type SDL_rect 2 qui contiendra les données des briques

     initbriques(briques); //on initialise les briques






    //Pour les 60 fps
    unsigned int frameLimit = SDL_GetTicks() + 16;


    if(init("Casse-Briques",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame)){

                state.g_bRunning=1;


    }else{

            return 1;//something's wrong

    }


    state.right=1;
    state.left=0;

    while(state.g_bRunning){

           handleEvents(&state,&paddle); //on appelle l'evenement qui permet de gérer le déplacement de la raquette
           deplacementBalle(&myGame,state,&ball, paddle, briques); //on appelle la fonction qui permet de déplacer la balle
           cutBitmapTexture(&myGame,state,paddle,ball,briques); //on appelle la fonction qui crée les textures et les affiche



        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
            delay(frameLimit);
            frameLimit = SDL_GetTicks() + 16;


    }

        destroy(&myGame);



        // unload the dynamically loaded image libraries
        IMG_Quit();
        //quit sdl2
        SDL_Quit();




  return 0;
}


int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame){


    //initialize SDL

    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
            //if succeeded create our window
            myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,height,width,flags);
            //if succeeded create window, create our render
            if(myGame->g_pWindow!=NULL){
                myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_ACCELERATED);
                SDL_SetRenderDrawColor(myGame->g_pRenderer, 0, 0, 0, 255);
                SDL_RenderClear(myGame->g_pRenderer);

                int flags=IMG_INIT_JPG|IMG_INIT_PNG;
                int initted=IMG_Init(flags);
                if((initted&flags) != flags) {
                        printf("IMG_Init: Failed to init required jpg and png support!\n");
                        printf("IMG_Init: %s\n", IMG_GetError());
                        // handle error
                }

            }


    }else{


        return 0;
    }




    return 1;


}



void cutBitmapTexture(game *myGame,gameState state, SDL_Rect paddle, ball ball, SDL_Rect2 briques[32]){
//BUT: Chercher les images à afficher, les attribuer à un rectangle et les afficher.
//ENTREE: instance du jeu, la raquette, la balle, et le tableau contenant les briques.
//SORTIE: L'affichage des sprites chargés.
        SDL_Rect rectangleDest; //on crée un rectangle qui contiendra la texture à afficher
        SDL_Rect rectangleSource;
        int i;


                myGame->g_surface = IMG_Load("./assets/paddle.png");//Chargement de l'image png






        if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", IMG_GetError());
            // handle error
        }

        if(myGame->g_surface){


                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
                 SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

                if(myGame->g_texture){
                    //1s = 1000ms
                    rectangleSource.x=0;//on cherche dans le sprite la position 0.0
                    rectangleSource.y=0;
                    rectangleSource.w=128;//1 image = w:128 et h:82. Cela permet de créer la taille que l'on extrait du sprite.
                    rectangleSource.h=32;




                    //Définition du rectangle dest pour dessiner le png
                    rectangleDest.x=paddle.x;//debut x
                    rectangleDest.y=paddle.y;//debut y
                    rectangleDest.w=100; //Largeur
                    rectangleDest.h=10; //Hauteur



                    SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest); //on crée une copie du sprite que l'on vient de créer.
<<<<<<< HEAD
                    SDL_DestroyTexture(myGame->g_texture); //on détruit l'ancienne copie pour libérer la mémoire.


=======
SDL_DestroyTexture(myGame->g_texture); //on détruit l'ancienne copie pour libérer la mémoire.

                    /*if(state.right)
                        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest); // Copie du sprite grâce au SDL_Renderer
                    if(state.left)
                        SDL_RenderCopyEx(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest,0,0,SDL_FLIP_HORIZONTAL);*/

                    //SDL_FLIP_NONE
                    //SDL_FLIP_HORIZONTAL
                    //SDL_FLIP_VERTICAL
>>>>>>> dd31b47dbd4ed4f1d77e2e7f410d04d72e44d450




                }

                else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }



        }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }

//Chargement de la balle
//même démarche que pour la raquette


                myGame->g_surface = IMG_Load("./assets/ball.png");//Chargement de l'image png






        if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", IMG_GetError());
            // handle error
        }

        if(myGame->g_surface){


                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
                 SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

                if(myGame->g_texture){
                    //1s = 1000ms

<<<<<<< HEAD
                    rectangleSource.x=0;//1 image tous les 100ms
=======
                       rectangleSource.x=0;//1 image tous les 100ms
>>>>>>> dd31b47dbd4ed4f1d77e2e7f410d04d72e44d450
                    rectangleSource.y=0;
                    rectangleSource.w=24;//1 image = w:128 et h:82
                    rectangleSource.h=24;

                    //Définition du rectangle dest pour dessiner le png
<<<<<<< HEAD
                    rectangleDest.x=ball.x;//debut x
=======
                 rectangleDest.x=ball.x;//debut x
>>>>>>> dd31b47dbd4ed4f1d77e2e7f410d04d72e44d450
                    rectangleDest.y=ball.y;//debut y
                    rectangleDest.w=24; //Largeur
                    rectangleDest.h=24; //Hauteur


                    SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest);
                    SDL_DestroyTexture(myGame->g_texture);

<<<<<<< HEAD

=======
                    /*if(state.right)
                        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest); // Copie du sprite grâce au SDL_Renderer
                    if(state.left)
                        SDL_RenderCopyEx(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest,0,0,SDL_FLIP_HORIZONTAL);*/

                    //SDL_FLIP_NONE
                    //SDL_FLIP_HORIZONTAL
                    //SDL_FLIP_VERTICAL
>>>>>>> dd31b47dbd4ed4f1d77e2e7f410d04d72e44d450



                }

                else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }



        }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }




//Chargement des blocs
//même démarche que pour la raquette et la balle, mais cette fois on parcourt un tableau et on affiche chaque bloc un par un.

for (i=0;i<32;i++){

                myGame->g_surface = IMG_Load("./assets/bricks.png");//Chargement de l'image png






        if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", IMG_GetError());
            // handle error
        }

        if(myGame->g_surface){


                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
                 SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

                if(myGame->g_texture){
                    //1s = 1000ms
               //on change de couleur du sprite à chaque fois, en prenant une brique différente (il faut juste changer les coordonnées du "prélèvement")
                switch(i%4){
                case 0:   rectangleSource.x=0;//1 image tous les 100ms
                    rectangleSource.y=0;
                    break;

                case 1: rectangleSource.x=64;//1 image tous les 100ms
                    rectangleSource.y=0;
                    break;

                 case 2:   rectangleSource.x=0;//1 image tous les 100ms
                    rectangleSource.y=24;
                    break;

                case 3: rectangleSource.x=64;//1 image tous les 100ms
                    rectangleSource.y=24;
                    break;

                }
                    rectangleSource.w=64;//1 image = w:128 et h:82
                    rectangleSource.h=24;

                    //Définition du rectangle dest pour dessiner le png
                    rectangleDest.x=briques[i].brique.x;//debut x
                    rectangleDest.y=briques[i].brique.y;//debut y
                    rectangleDest.w=briques[i].brique.w; //Largeur
                    rectangleDest.h=briques[i].brique.h; //Hauteur


                 if (briques[i].destroyed!=True) { SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest);
                 }
                  SDL_DestroyTexture(myGame->g_texture);

<<<<<<< HEAD

=======
                    /*if(state.right)
                        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest); // Copie du sprite grâce au SDL_Renderer
                    if(state.left)
                        SDL_RenderCopyEx(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest,0,0,SDL_FLIP_HORIZONTAL);*/

                    //SDL_FLIP_NONE
                    //SDL_FLIP_HORIZONTAL
                    //SDL_FLIP_VERTICAL
>>>>>>> dd31b47dbd4ed4f1d77e2e7f410d04d72e44d450



                }

                else{
                        fprintf(stdout,"Echec  (%s)\n",SDL_GetError());
                }



        }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }


}
























  SDL_RenderPresent(myGame->g_pRenderer); // Affichage

                    SDL_RenderClear(myGame->g_pRenderer);





















    destroyTexture(myGame);

}

void delay(unsigned int frameLimit){
    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}




void destroy(game *myGame){

    //Destroy render
    if(myGame->g_pRenderer!=NULL)
        SDL_DestroyRenderer(myGame->g_pRenderer);


    //Destroy window
    if(myGame->g_pWindow!=NULL)
        SDL_DestroyWindow(myGame->g_pWindow);

}



void destroyTexture(game *myGame){

    //Destroy texture
    if(myGame->g_texture!=NULL)
            SDL_DestroyTexture(myGame->g_texture);


}

