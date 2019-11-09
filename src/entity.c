#include "entity.h"

void mems(void) {
	memset(&game, 0, sizeof(declare));
	memset(&player, 0, sizeof(Entity));
	memset(&emily, 0, sizeof(Entity));
	memset(&ani, 0, sizeof(Entity));
}

void Entity_Init(void) {
	player.x = 0; player.y = 0;
	player.w = 48; player.h = 46;
	emily.x = 150; emily.y = 200;
	emily.w = 50; emily.h = 50;
	ani.x = 250; ani.y = 250;
	ani.w = 48; ani.h = 46;
}

void Entity_InitTexture(void) {
	player.texture = loadTexture("gallery/player_right.png");
	emily.texture = loadTexture("gallery/idle_1.png");
	ani.texture = loadTexture("gallery/animation.png");
}

void Entity_preScene() {
	blit(player.texture, player.x, player.y);
	blit(emily.texture, emily.x, emily.y);
	ani1 = &ani;
	animation(ani.texture, 
		  ani.x, ani.y, ani.w, ani.h,
		  ani1, 3, 5);// max frames and seconds between frames
	animation(ani.texture, 
		  ani.x + 100, ani.y + 100, ani.w, ani.h,
		  ani1, 3, 5);// max frames and seconds between frames
}

void Entity_Collisions(void) {
	// Emily collision
	collision1 = &player;
	collision2 = &emily;
	if(collision(collision1, collision2) == 1) { 
		NegativeNavigation();
	}
	if(Ifhit(collision1, collision2) == 1) { 
		emily.hit = 1;
	}
	// ani collision
	collision2 = &ani;
	if(collision(collision1, collision2) == 1) { NegativeNavigation();}
}

void DestroyTexture(void) {
	SDL_DestroyTexture(player.texture);
	SDL_DestroyTexture(emily.texture);
	SDL_DestroyTexture(ani.texture);
}

/*	OLD COLLISION
void Entity_Collisions(void) {
	if(collision(player.x, player.y, player.w, player.h, 
			     emily.x, emily.y, emily.w, emily.h) == 1) {
		NegativeNavigation();
	}
	if(collision(player.x, player.y, player.w, player.h, 
			     ani.x, ani.y, ani.w, ani.h) == 1) {
		NegativeNavigation();
	}
}
*/
