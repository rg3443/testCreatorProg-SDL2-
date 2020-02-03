#include "trueQAB.h"

void QAB::setup()
{
   // SCREEN_W = 270;
   // SCREEN_H = 450;

    SCREEN_W = save_screen.getw();
    SCREEN_H = save_screen.geth();
    etSCREEN_W = save_screen.getetw();
    etSCREEN_H = save_screen.geteth();
    save_screen.setetwh(cords(SCREEN_W,SCREEN_H)); // START SCREEN
    gameplay = false;
    global_object_id_counter = 0;

    plrpos.x = 49;
    plrpos.y = 49;

    TTF_Init();
     Sans = TTF_OpenFont("Raleway-ExtraBold.ttf", 26);
    // õìõæõõêõãþæõú áÿåöí sdl
   if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
       std::cout << SDL_GetError() << std::endl;
   }
          // ÿíãäþìõå íéìþ
   window = SDL_CreateWindow("prog", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
   if (window == 0){
       std::cout << SDL_GetError() << std::endl;
   }
   // ÿíãäþìõå ïåìäåïþ
   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   if (renderer == 0){
       std::cout << SDL_GetError() << std::endl;
   }
   
   eternal_renderer = &renderer;
   eternal_window = &window;
   wnd_surface = SDL_GetWindowSurface(window);     
}

void QAB::resize_window(int nscw, int nsch)
{
         //todo: åáó÷àÿ ìàñøòàáèðóåìîñòü ñäåëàòü
         //ÂÛ×ÈÑËßÅÌ ÏÐÎÖÅÍÒ ÓÂÅËÈ×ÅÍÈß ÈËÈ ÓÌÅÍÜØÅÍÈß
         //ÍÀÊÈÄÛÂÀÅÌ Ê ÏÅÐ ÏÐÎÖ ÓÂÅËÈ×
         //ÇÀÁÈÐÀÅÌ ÏÅÐÌÛ Â ÏÐÎÃÅ
         printf("\t\tOLD SCREEN  %d %d | NEW SCREEN %d %d",SCREEN_W,SCREEN_H,nscw,nsch);
        float new_proc;
        if(SCREEN_W - nscw != 0) {
            new_proc = to_float(nscw) / (to_float(etSCREEN_W) / 100);
            cout << "NEW PROC IS " << new_proc << endl;
           // mashx = new_proc / 100.f; 
        } else if(SCREEN_H - nsch != 0) {
            new_proc = to_float(nsch) / (to_float(etSCREEN_H) / 100);
          //  mashy = new_proc / 100.f; 
        }
        SCREEN_W = nscw; SCREEN_H = nsch;
        SDL_DestroyWindow(window);
        window = SDL_CreateWindow("prog", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        eternal_renderer = &renderer;
        stringstream ss1;
        stringstream ss2;
        ss1 << SCREEN_W;
        ss2 << SCREEN_H;
        string buf = ss1.str() + "\n" + ss2.str();
        wnd_surface = SDL_GetWindowSurface(window);
        eternal_window = &window;
        
        save_screen.setwh(cords(SCREEN_W,SCREEN_H));    
        //save_screen.setmasht(fcords(mashx,mashy)); 
}
