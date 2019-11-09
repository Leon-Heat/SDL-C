#include "util.h"

int collision(Entity *r1, Entity *r2) {
	if(r1->x + r1->w >= r2->x && r1->x <= r2->x + r2->w) {
		if(r1->y + r1->h >= r2->y && r1->y <= r2->y + r2->h) {
			return 1;
		}
	}
}

int Ifhit(Entity *r1, Entity *r2) {
	if(r1->x + r1->w >= r2->x - 20 && r1->x <= r2->x + r2->w + 20) {
		if(r1->y + r1->h >= r2->y - 20 && r1->y <= r2->y + r2->h + 20) {
			printf("Ifhit == 1\n");
			return 1;
		}
	}
}

int Count(clock_t t, int time) {
	t = clock() - t;
	time = floor(10 * (double)t/CLOCKS_PER_SEC);
	return time;
}

int interval(Entity *k, int frame_max, int seconds) {
	k->a2 = Count(count.t, count.time);
	if(k->a2 == k->a1 + 1) {
		k->a1 += seconds;
		if( k->frame <= frame_max) {
			k->frame += 1;
			if(k->frame == frame_max + 1) {
				k->frame = 1;
			}
		}
	}
}

/* OLD COLLISION
int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	if(x1 + w1 >= x2 && x1 <= x2 + w2) {
		if(y1 + h1 >= y2 && y1 <= y2 + h2) {
			return 1;
		}
	}
}
*/
