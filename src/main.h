#include "common.h"

//	Declare Variable
declare game;
second count;
Entity player;
Entity emily;
Entity ani;
Entity *ani1;
	//	entity util
Entity *collision1;
Entity *collision2;


// init
extern void Init(void);
extern void Quit(void);
//	draw
extern void preScene(void);
extern void PresentScene(void);
//	input
extern void Event(void);
extern void Navigation(void);
// entity
extern void Entity_preScene();
extern void Entity_Collisions(void);
// util
extern int Count(clock_t t, int d2);
