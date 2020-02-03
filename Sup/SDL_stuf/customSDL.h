#ifndef CUSTOMSDL_H_INCLUDED
#define CUSTOMSDL_H_INCLUDED




/*core.h*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
#include "SDL.h"
#include "SDL_ttf.h"
//#include "SDL_image.h"
//#include "gGlobal.h"
#include "cGraf.h"
#include "Surface_hand.h"
#include "../../pcgGlobal.h"
#include "GSDL.h"
//SDL_Renderer * renderer; g_get_rend(renderer);
//SDL_Window * window; g_get_window(window);
//TEXTURE LOADING AND DRAW

/*

	NEEDS:
		bolditalic.ttf
		SDL2
		...

*/



class customSDL {
public:
    customSDL() { }
    void setup(SDL_Renderer * rende) { this->rende = rende;    Sans = NULL; }
    void setup(SDL_Renderer ** etrend) { eternal_rend = etrend; rende = *etrend; Sans = NULL; Sans = TTF_OpenFont("ExtraBold.ttf", 16); }
    void setup(SDL_Renderer * rende,int tsize) { this->rende = rende;    Sans = NULL; Sans = TTF_OpenFont("ExtraBold.ttf", tsize);}
    void insert_window(SDL_Window ** eternal_window) { window = eternal_window; }
    void set_background_color(SDL_Color clr) { background = clr; }
    SDL_Texture* LoadImage(std::string file);
    void ApplySurface(int x, int y, SDL_Texture *tex);
    void CrtTexture(int x, int y,std::string file);
    void DrawRect(int y1, int y2, int x1, int x2, int clr1, int clr2, int clr3, int clr4);
    void DrawRect(int x, int y, int clr1, int clr2, int clr3);
    void new_DrawRect(int x,int y,int w, int h, int r, int g, int b);
    void DrawRect(int y1, int y2, int x1, int x2);

    void DrawText(std::string text,int x, int y, int w, int h, SDL_Color color, int big);
    void DrawText(std::string text, int x, int y, int w, int h, int r, int g,int b, int big);
    void DrawPeremen(string name, int perem, int x, int y, int w, int h,SDL_Color color, int big);
    void SDLprint(string text, SSDLTextParam text_param,cords pos,SDL_Color clr,int tsize);
    void DrawConvertedImage(string path, cords pos, cords size);
protected:
    TTF_Font * Sans;
    SDL_Renderer * rende;
    SDL_Renderer ** eternal_rend;
    SDL_Color background;
    SDL_Window ** window;
    //static SDL_Window * window;
};




/*                                    stringstream ss;
                                    ss << a;
                                string str = ss.str();
                                DrawText(str, White, 200, 200, 200, 100);*/

#endif // CUSTOMSDL_H_INCLUDED
