#include "Viewport.h"

Viewport::Viewport(int x,int y,int w,int h,SDL_Renderer* rnd)
{
                       this->rnd = rnd;
    SDL_Rect port;
    port.x = x;
    port.y = y;
    port.w = w;
    port.h = h;
    SDL_RenderSetViewport( rnd,&port );                       
}

void Viewport::replace(int x,int y,int w,int h)
{
    SDL_Rect port;
    port.x = x;
    port.y = y;
    port.w = w;
    port.h = h;
    SDL_RenderSetViewport( rnd,&port );                       
     
}
