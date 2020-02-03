#ifndef CLOADWINDOW_H_INCLUDED
#define CLOADWINDOW_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <string>
#include <string>
#include <sstream>
using namespace std;
#include "SDL.h"
#include "SDL_ttf.h"
#include "../../pcgGlobal.h"
#include "../SDL_stuf/CRenderGate.h"
#include "../SDL_stuf/baseSDL.h"
/*
	this window loading before "main" window
*/

class CLoadWindow {
public:
	CLoadWindow() { renderer = nullptr; window = nullptr;	}
	void setup(string name, cords pos, cords size);
	virtual void draw_load_screen();
	void destroy();
protected:
	cords pos,size;
	SDL_Renderer* renderer;
	SDL_Window* window;
	CRenderGate draw_gate;
	baseSDL cast;
};

#endif
