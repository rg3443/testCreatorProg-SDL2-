#include "customSDL.h"


SDL_Texture* customSDL::LoadImage(std::string file)
{

   SDL_Surface *loadedImage = nullptr;
   SDL_Texture *texture = nullptr;
    loadedImage = SDL_LoadBMP(file.c_str());

     SDL_SetColorKey( loadedImage,SDL_TRUE,SDL_MapRGB(loadedImage->format,background.r,background.g,background.b));

   if (loadedImage != 0){
       texture = SDL_CreateTextureFromSurface(rende, loadedImage);
   }
   else
       std::cout << SDL_GetError() << std::endl;

   Surface_hand deleter(loadedImage);
   return texture;
}

void customSDL::DrawConvertedImage(string path, cords pos, cords size)
{
   SDL_Surface *loadedImage = nullptr;
   SDL_Surface *optsurf = nullptr;
   SDL_Texture *texture = nullptr;
   loadedImage = SDL_LoadBMP(path.c_str());

   SDL_SetColorKey( loadedImage,SDL_TRUE,SDL_MapRGB(loadedImage->format,background.r,background.g,background.b));
   optsurf = SDL_ConvertSurface(loadedImage,SDL_GetWindowSurface(*(window))->format,0);
   SDL_Rect rect;
   rect.x = pos.x;
   rect.y = pos.y;
   rect.w = size.x - pos.x;
   rect.h = size.y - pos.y;
   SDL_BlitScaled(optsurf,NULL,optsurf,&rect);
   
   
   if (optsurf != 0){
       texture = SDL_CreateTextureFromSurface(rende, optsurf);
   }
   
   Surface_hand deleter1(loadedImage);
   Surface_hand deleter2(optsurf);
   ApplySurface(pos.x,pos.y,texture);
}

void customSDL::ApplySurface(int x, int y, SDL_Texture *tex)
{
    rende = *eternal_rend;
   SDL_Rect pos;
   pos.x = x;
   pos.y = y;
   SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
   SDL_RenderCopy(rende, tex, NULL, &pos);
   SDL_DestroyTexture( tex );
}

void customSDL::CrtTexture(int x, int y, std::string file)
{
    try {
        SDL_Texture *tex = LoadImage( file.c_str() );
        if(tex == nullptr) throw "ERRORE: IMAGE NOT FOUND\n";
        ApplySurface(x,y,tex);
        SDL_DestroyTexture( tex );
    }
    catch(const char* eror) { printf(eror); }
}


void customSDL::DrawRect(int y1, int y2, int x1, int x2, int clr1, int clr2, int clr3, int clr4)
{
    rende = *eternal_rend;
    SDL_Rect fillRect = { y1, x1, y2, x2 };
    SDL_SetRenderDrawColor( rende, clr1, clr2, clr3, clr4 );
    SDL_RenderFillRect( rende, &fillRect );
}


void customSDL::DrawRect(int x, int y, int clr1, int clr2, int clr3)
{
    rende = *eternal_rend;
    SDL_Rect fillRect = { y, x, (y+250), (x+150) };
    SDL_SetRenderDrawColor( rende, clr1, clr2, clr3, 0x00 );
    SDL_RenderFillRect( rende, &fillRect );
}

void customSDL::new_DrawRect(int x,int y,int w, int h, int r, int g, int b)
{
    rende = *eternal_rend;
    SDL_Rect fillRect;
    fillRect.x = x;
    fillRect.y = y;
    fillRect.w = w;
    fillRect.h = h;
    SDL_SetRenderDrawColor( rende, r, g, b, 255 );
    SDL_RenderFillRect( rende, &fillRect );
}

void customSDL::DrawRect(int y1, int y2, int x1, int x2)
{
    rende = *eternal_rend;
    SDL_Rect fillRect = { y1, x1, y2, x2 };
    SDL_SetRenderDrawColor( rende, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderFillRect( rende, &fillRect );
}


void customSDL::DrawText(std::string text, int x, int y, int w, int h, SDL_Color color, int big)
{
     TTF_CloseFont(Sans);
     Sans = nullptr;
     Sans = TTF_OpenFont("ExtraBold.ttf",big);
    rende = *eternal_rend;
    setlocale(LC_ALL, "Russian");
    SDL_Surface* surfaceMessage = NULL;
    surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), color);
    SDL_Texture* Message = NULL;
    Message = SDL_CreateTextureFromSurface(rende, surfaceMessage);
    Surface_hand deleter(surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = w;
    Message_rect.h = h;

    SDL_QueryTexture(Message, NULL, NULL, &Message_rect.w, &Message_rect.h);
    //UPDATE/GAMELOOP AREA, I DIDN'T REALLY PASTE THE WHOLE PART
    SDL_RenderCopy(rende, Message, NULL, &Message_rect);
    SDL_DestroyTexture(Message);
}

void customSDL::DrawText(std::string text, int x, int y, int w, int h, int r, int g,int b, int big)
{
    rende = *eternal_rend;
    SDL_Color color; color.r=r;color.g=g;color.b=b;
    setlocale(LC_ALL, "Russian");
    //TTF_Font* Sans = NULL;
    //Sans = TTF_OpenFont("ExtraBold.ttf", big);
    SDL_Surface* surfaceMessage = NULL;
    surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), color);
    SDL_Texture* Message = NULL;
    Message = SDL_CreateTextureFromSurface(rende, surfaceMessage);
    Surface_hand deleter(surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = w;
    Message_rect.h = h;

    SDL_QueryTexture(Message, NULL, NULL, &Message_rect.w, &Message_rect.h);
    //UPDATE/GAMELOOP AREA, I DIDN'T REALLY PASTE THE WHOLE PART
    SDL_RenderCopy(rende, Message, NULL, &Message_rect);
    SDL_DestroyTexture(Message);
    //TTF_CloseFont();
}

void customSDL::DrawPeremen(string name, int perem, int x, int y, int w, int h,SDL_Color color, int big)
{
    rende = *eternal_rend;
    stringstream to;
    to << perem;
    string res = name.c_str() + to.str();
    DrawText(res,  x,y, w,h,color,big);
}

void customSDL::SDLprint(string text, SSDLTextParam text_param,cords pos,SDL_Color clr,int tsize)
{
    rende = *eternal_rend;
    string res;
    int int_counter = -1;
    int float_counter = -1;
    int string_counter = -1;
    //cout << text << endl;
    //while(!done)
    for(int char_id=0;char_id<text.size();char_id++)
    {
        //cout << text << endl;
        if(text[char_id] == '%')
        {
            stringstream ss;
            switch(text[char_id+1])
            {
            case 'd':
                int_counter++;
                ss << text_param.integer[int_counter];
                 res = ss.str();
                text = text.erase(char_id,2);
                text = text.insert((char_id),res);
            break;
            case 'f':
                float_counter++;
                ss << text_param.floater[float_counter];
                 res = ss.str();
                text = text.erase(char_id,2);
                text = text.insert((char_id),res);
            break;
            case 's':
                string_counter++;
                text = text.erase(char_id,2);
                text = text.insert( char_id, text_param.stringer[string_counter].c_str() );
            break;
            }
        } else if(text[char_id] == EOF) {
            cout << "\t\tend\n";
            //done = true;
        }
    }
    //cout << text << endl;
    this->DrawText(text,pos.x,pos.y,10,10,clr,tsize);
}



