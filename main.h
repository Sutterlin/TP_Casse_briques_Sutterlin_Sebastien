
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

//la balle, avec ses coordonn�es et sa direction.
typedef struct ball{

    double x;
    double y;
    int direction;



}ball;
//on cr�e un enum qui fait office de bool�en, pour savoir si la brique est d�truite ou non.
typedef enum destroyed{
True,False



}destroyed;

//les briques, avec leurs coordonn�es en x, y et leurs dimensions (contenues dans sdl rect), et l'enum cr�e auparavant.
typedef struct SDL_Rect2{

    SDL_Rect brique;
    destroyed destroyed;




}SDL_Rect2;




int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame);

void cutBitmapTexture(game *myGame,gameState state, SDL_Rect paddle, ball ball,SDL_Rect2 briques[32]);
void delay(unsigned int frameLimit);
void destroyTexture(game *myGame);
void destroy(game *myGame);


