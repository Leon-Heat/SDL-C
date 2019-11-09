#include "init.h"

void Init(void) {
	mems();
	game.window = SDL_CreateWindow("test.c",
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								WINDOWS_LENGTH,
								WINDOWS_HEIGHT,
								0
								);
	game.renderer = SDL_CreateRenderer(game.window,
										-1,
										SDL_RENDERER_ACCELERATED
										);
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
	Entity_Init();
	Entity_InitTexture();
}

void Quit(void) {
	SDL_DestroyWindow(game.window);
	SDL_DestroyRenderer(game.renderer);
	DestroyTexture();
	SDL_Quit();
}
