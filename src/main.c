#include "main.h"

int main() {
	Init();
	while(1){
		preScene();
		Event();
		Navigation(); // texture dynamic included
		Entity_Collisions();
		Entity_preScene();
		PresentScene();
		SDL_Delay(1);
	}
	Quit();	
}
