

typedef struct game{


     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_texture;
     SDL_Surface *g_surface;


}game;

typedef struct gameState{

    int g_bRunning;
    int left;
    int right;


}gameState;


typedef struct coordonnees{

    double x;
    double y;



}coordonnees;


typedef struct ball{

    double x;
    double y;
    int direction;



}ball;

typedef enum destroyed{
True,False



}destroyed;


typedef struct SDL_Rect2{

    SDL_Rect brique;
    destroyed destroyed;




}SDL_Rect2;


void deplacementBalle(game *MyGame,gameState state, ball *ball, SDL_Rect paddle, SDL_Rect2 briques[32]);








