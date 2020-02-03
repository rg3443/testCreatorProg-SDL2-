#include "CLoadWindow.h"

void CLoadWindow::setup(string name, cords pos, cords size)
{
   if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
       std::cout << SDL_GetError() << std::endl;
   }
          // янгдюмхе нймю
   window = SDL_CreateWindow(name.c_str(), pos.x,pos.y, size.x, size.y, SDL_WINDOW_SHOWN);
   if (window == nullptr){
       std::cout << SDL_GetError() << std::endl;
   }
   // янгдюмхе пемдепю
   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if (renderer == nullptr){
       std::cout << SDL_GetError() << std::endl;
   }	
   draw_gate.setup(&renderer,&window,Red);
   cast.setup(&renderer,&window);
}

void CLoadWindow::draw_load_screen()
{
	draw_gate.enter();
	cast.DrawImage("misc/fm_big_logo.bmp",cords(0,0),cords(100,100));
	//cast.DrawOutRect(cords(10,10),cords(100,100),typecolor(100,100,100));
	draw_gate.exit();
}

void CLoadWindow::destroy()
{
	SDL_DestroyWindow(window);
}
