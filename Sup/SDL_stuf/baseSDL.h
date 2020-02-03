#ifndef BASESDL_H_INCLUDED
#define BASESDL_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <string>
#include <sstream>
using namespace std;
#include "SDL.h"
#include "SDL_ttf.h"
#include "cGraf.h"
#include "Surface_hand.h"
#include "../../pcgGlobal.h"
#include "GSDL.h"

class baseSDL {
public:
    baseSDL(){ Sans = TTF_OpenFont("ExtraBold.ttf",16); }
    void setup(SDL_Renderer ** etrend, SDL_Window ** etwind);
    void refresh_pointers();
    void SetColorKey(SDL_Color clr);
    
    //render allready exist surface
    void DrawSurface(SSurface * surf);
    
    //create and render surface
    void DrawLine(cords p1, cords p2, SDL_Color clr);
    void DrawImage(string path, cords p1, cords p2);
	void DrawImage(string path,cords p1,cords p2,SDL_Rect * field_to_draw);
    void DrawOutRect(cords p1, cords p2, SDL_Color clr);
    void DrawFillRect(cords p1, cords p2, SDL_Color clr);
    void DrawDoubleRect(cords p1, cords p2, SDL_Color c1,SDL_Color c2);
    void DrawText(string text, cords pos, SDL_Color clr, int big);
    void SDLprint(string text, SSDLTextParam text_param,cords pos,SDL_Color clr,int tsize);

protected:
    SDL_Renderer ** eternal_rend;
    SDL_Window ** eternal_window;
    SDL_Window * current_window;
    SDL_Renderer * current_rend;
    SDL_Surface * window_surface;
    TTF_Font * Sans;
    //support classes
    View grf;
    SDL_Color colorkey;
          
};

#endif
