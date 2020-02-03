#ifndef CRENDERGATE_H_INCLUDE
#define CRENDERGATE_H_INCLUDE

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "SDL.h"
#include "SDL_ttf.h"

class CRenderGate {
public:
	CRenderGate() {}
	//	ACCEPT ETERNAL RENDER & ETERNAL WINDOW + BACKGROUND COLOR ( typecolor(r,g,b) or SDL_Color variable )
	void setup(SDL_Renderer ** rnd, SDL_Window ** wnd,SDL_Color background){
		eternal_render = rnd;
		eternal_window = wnd;
		background_color = background;
	}
	//	PLACE THIS BEFORE DRAW
	void enter(){
		SDL_SetRenderDrawColor(*(eternal_render), background_color.r,background_color.g,background_color.b,background_color.a);
		SDL_RenderClear(*(eternal_render));
	}
	//	PLACE THIS AFTER DRAW
	void exit() { SDL_RenderPresent(*(eternal_render)); }
protected:
	SDL_Renderer ** eternal_render;
	SDL_Window ** eternal_window;
	SDL_Color background_color;
};

#endif

