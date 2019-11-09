#include "draw.h"

void preScene(void) {
	SDL_SetRenderDrawColor(game.renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(game.renderer);
}

void PresentScene(void) {
	SDL_RenderPresent(game.renderer);
}

void Rect(int x, int y) {
	SDL_Rect rect1 = {	(WINDOWS_LENGTH / 2 - (WINDOWS_LENGTH / 15) / 2) + x,
					  	(WINDOWS_HEIGHT / 2 - (WINDOWS_HEIGHT / 15) / 2) + y,
					   	WINDOWS_LENGTH / 15,
					  	WINDOWS_HEIGHT / 15,
					};
	SDL_SetRenderDrawColor(game.renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(game.renderer, &rect1);
}

SDL_Texture *loadTexture(char *filename)
{
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(game.renderer, filename);

	return texture;
}

void blit(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest = { x, y };
	
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	
	SDL_RenderCopy(game.renderer, texture, NULL, &dest);
}

void animation(SDL_Texture *texture, int x, int y, int w, int h,  
Entity *k, int frame_max, int seconds)
{	
	interval(k, frame_max, seconds);	
	SDL_Rect dest = {x, y, w, h};
	SDL_Rect src = { (k->frame - 1) * w, 0, w, h};
	
	SDL_RenderCopy(game.renderer, texture, &src, &dest);
}
