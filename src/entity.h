#include "common.h"

//	Extern Variable
extern declare game;
extern second count;
extern Entity player;
extern Entity emily;
extern Entity ani;
// util
extern Entity *ani1;
extern Entity *collision1;
extern Entity *collision2;

//	draw
extern SDL_Texture *loadTexture(char *filename);
extern void blit(SDL_Texture *texture, int x, int y);
extern void animation(SDL_Texture *texture, 
					  int x, int y,	int w, int h,
					  Entity *k, int frame_max, int seconds);
extern void PresentScene(void);
//	input
extern void NegativeNavigation(void);
//	util
extern int collision(Entity *r1, Entity *r2);
extern int Ifhit(Entity *r1, Entity *r2);
//extern int collision(int x1, int y1, int w1, int h1, 
//					 int x2, int y2, int w2, int h2);
