#include "input.h"

void doKeyUp(SDL_KeyboardEvent *e) {
	if(e->repeat == 0) {
		switch(e->keysym.scancode) {
			case SDL_SCANCODE_UP:
				game.up = 0;
				break;
			case SDL_SCANCODE_DOWN:
				game.down = 0;
				break;
			case SDL_SCANCODE_LEFT:
				game.left = 0;
				break;
			case SDL_SCANCODE_RIGHT:
				game.right = 0;
				break;
			case SDL_SCANCODE_Z:
				game.talk = 0;
				break;
		}
	}
}

void doKeyDown(SDL_KeyboardEvent *e) {
	Entity player;
	if(e->repeat == 0) {
		switch(e->keysym.scancode) {
			case SDL_SCANCODE_UP:
				game.up = 1;
				break;
			case SDL_SCANCODE_DOWN:
				game.down = 1;
				break;
			case SDL_SCANCODE_LEFT:
				game.left = 1;
				break;
			case SDL_SCANCODE_RIGHT:
				game.right = 1;
				break;
			case SDL_SCANCODE_Z:
				game.talk = 1;
				break;
		}
	}
}

void Event(void) {
	Entity player;
	SDL_Event e;
	while(SDL_PollEvent(&e)){
		switch(e.type){
			case SDL_QUIT:
				exit(0);
				break;
			case SDL_KEYUP:
				doKeyUp(&e.key);
				break;
			case SDL_KEYDOWN:
				doKeyDown(&e.key);
				break;
			default:
				break;
		}
	}
}

void Navigation(void) {
		if(game.up && !game.left && !game.right) 	{ 
			player.y -= WASD_SPEED;
			if(player.texture_up == 1){ }
			else if(player.texture_up == 0){
				player.texture = loadTexture("gallery/player_up.png");
				player.texture_up = 1;
				player.texture_down = 0;
				player.texture_right = 0;
				player.texture_left = 0;
				player.texture_left_up = 0;
				player.texture_left_down = 0;
				player.texture_right_up = 0;
				player.texture_right_down = 0;
			}
		}
		if(game.down && !game.left && !game.right)	{ 
				player.y +=  WASD_SPEED;
			if(player.texture_down == 1){ }
			else {
				player.texture = loadTexture("gallery/player_down.png");
				player.texture_up = 0;
				player.texture_down = 1;
				player.texture_right = 0;
				player.texture_left = 0;
				player.texture_left_up = 0;
				player.texture_left_down = 0;
				player.texture_right_up = 0;
				player.texture_right_down = 0;
			}
		}
		if(game.left && !game.up && !game.down)	{ 
			player.x -= WASD_SPEED;
			if(player.texture_left == 1){ }
			else {
				player.texture = loadTexture("gallery/player_left.png");
				player.texture_up = 0;
				player.texture_down = 0;
				player.texture_right = 0;
				player.texture_left = 1;
				player.texture_left_up = 0;
				player.texture_left_down = 0;
				player.texture_right_up = 0;
				player.texture_right_down = 0;
			}
		}
		if(game.right && !game.up && !game.down)	{ 
			player.x += WASD_SPEED;
			if(player.texture_right == 1){ }
			else {
				player.texture = loadTexture("gallery/player_right.png");
				player.texture_up = 0;
				player.texture_down = 0;
				player.texture_right = 1;
				player.texture_left = 0;
				player.texture_left_up = 0;
				player.texture_left_down = 0;
				player.texture_right_up = 0;
				player.texture_right_down = 0;
			}
		}
		if(game.left && game.up)	{ 
			player.x -= QEZC_SPEED;
			player.y -= QEZC_SPEED;
			if(player.texture_left_up == 1){ }
			else {
				player.texture = loadTexture("gallery/player_left_up.png");
				player.texture_up = 0;
				player.texture_down = 0;
				player.texture_right = 0;
				player.texture_left = 0;
				player.texture_left_up = 1;
				player.texture_left_down = 0;
				player.texture_right_up = 0;
				player.texture_right_down = 0;
			}
		}
		if(game.left && game.down)	{ 
			player.x -= QEZC_SPEED;
			player.y += QEZC_SPEED;
			if(player.texture_left_down == 1){ }
			else {
				player.texture = loadTexture("gallery/player_left_down.png");
				player.texture_up = 0;
				player.texture_down = 0;
				player.texture_right = 0;
				player.texture_left = 0;
				player.texture_left_up = 0;
				player.texture_left_down = 1;
				player.texture_right_up = 0;
				player.texture_right_down = 0;
			}
		}
		if(game.right && game.up)	{ 
			player.x += QEZC_SPEED;
			player.y -= QEZC_SPEED;
			if(player.texture_right_up == 1){ }
			else {
				player.texture = loadTexture("gallery/player_right_up.png");
				player.texture_up = 0;
				player.texture_down = 0;
				player.texture_right = 0;
				player.texture_left = 0;
				player.texture_left_up = 0;
				player.texture_left_down = 0;
				player.texture_right_up = 1;
				player.texture_right_down = 0;
			}
		}
		if(game.right && game.down)	{ 
			player.x += QEZC_SPEED;
			player.y += QEZC_SPEED;
			if(player.texture_right_down == 1){ }
			else {
				player.texture = loadTexture("gallery/player_right_down.png");
				player.texture_up = 0;
				player.texture_down = 0;
				player.texture_right = 0;
				player.texture_left = 0;
				player.texture_left_up = 0;
				player.texture_left_down = 0;
				player.texture_right_up = 0;
				player.texture_right_down = 1;
			}
		}
		if(emily.hit && game.talk)	{ 
			printf("Talk to emily\n");
		}	
}


void NegativeNavigation(void) {
		if(game.up) 	{ 
			player.y += WASD_SPEED;
		}
		if(game.down)	{ 
			player.y -= WASD_SPEED;
		}
		if(game.left)	{ 
			player.x += WASD_SPEED;
		}
		if(game.right)	{ 
			player.x -= WASD_SPEED;
		}
		if(game.left && game.up)	{ 
			player.x += QEZC_SPEED;
			player.y += QEZC_SPEED;
		}
		if(game.left && game.down)	{ 
			player.x += QEZC_SPEED;
			player.y -= QEZC_SPEED;
		}
		if(game.right && game.up)	{ 
			player.x -= QEZC_SPEED;
			player.y += QEZC_SPEED;
		}
		if(game.right && game.down)	{ 
			player.x -= QEZC_SPEED;
			player.y -= QEZC_SPEED;
		}
		if(emily.hit && game.talk)	{ 
			printf("Talk to emily\n");
		}	
}
