#ifndef SURFACE_HAND_H_INCLUDED
#define SURFACE_HAND_H_INCLUDED

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
#include "../../pcgGlobal.h"

class Surface_hand {
public:
    Surface_hand() {}
    Surface_hand(SDL_Surface*  surface) { set_surface(surface); }
    ~Surface_hand() { SDL_FreeSurface(m_surface); }
    
    void set_surface(SDL_Surface* surface) { m_surface = surface; } 
    SDL_Surface * get_surface() { return m_surface; }   
protected:
    SDL_Surface*  m_surface;
          
};

#endif
