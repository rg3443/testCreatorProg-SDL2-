#ifndef CGRAF_H_INCLUDED
#define CGRAF_H_INCLUDED

#include <iostream>

#include <ctime>

#include <vector>

#include <stdio.h>
using namespace std;
#include "SDL.h"
#include "customSDL.h"
//#include "gGlobal.h"
//#include "gText.h"
//#include "cButtons.h"
#include <iostream>

#include <ctime>

#include <vector>

using namespace std;
#include "SDL.h"
#include "../../pcgGlobal.h"

class View {
public:
    View() {}
    void setup(SDL_Renderer * renderer, SDL_Window * window) { this->window = window; this->renderer = renderer; }
    void setup(SDL_Renderer ** etrenderer, SDL_Window * window) { eternal_renderer = etrenderer; this->window = window; }
    void setup(SDL_Renderer ** etrenderer, SDL_Window ** etwind) { eternal_renderer = etrenderer; eternal_window = etwind; }
    void Line(cords p1, cords p2,SDL_Color c);
    void baseSquare(cords p1, cords p4, SDL_Color c);
    void fillSquare(cords p1, cords p4, SDL_Color c);
    void fillSquare(int x,int y,int w,int h,SDL_Color clr);
    void baseShit(cords p1, cords p4,SDL_Color c);
	void baseCircle(cords p_centre, int diametr, SDL_Color clr);

protected:
    SDL_Renderer ** eternal_renderer;
    SDL_Window ** eternal_window;
    SDL_Window * window;
    SDL_Renderer * renderer;

};


#endif // CGRAF_H_INCLUDED
