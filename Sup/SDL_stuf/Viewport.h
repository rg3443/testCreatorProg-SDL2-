#ifndef VIEWPORT_H_INCLUDED
#define VIEWPORT_H_INCLUDED

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
#include "SDL.h"
#include "../../pcgGlobal.h"
class Viewport {
public:
    Viewport() {}
    Viewport(int x,int y,int w,int h, SDL_Renderer * rnd);
    void replace(int x,int y,int w,int h);
protected:
    vector<SDL_Rect> port;      
    SDL_Renderer* rnd;
};  

#endif
