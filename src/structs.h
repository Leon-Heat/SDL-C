typedef struct {
	SDL_Window *window;
	SDL_Renderer *renderer;
	int up;
	int down;
	int left;
	int right;
	int talk;
} declare;

typedef struct {
	float x;
	float y;
	float w;
	float h;
	int frame;
//texture
	int texture_up;
	int texture_down;
	int texture_left;
	int texture_right;
	int texture_left_up;
	int texture_left_down;
	int texture_right_up;
	int texture_right_down;
	SDL_Texture *texture;
	int a1;
	int a2;
	int hit;
} Entity;

typedef struct {
	clock_t t;
	int time;
} second;
