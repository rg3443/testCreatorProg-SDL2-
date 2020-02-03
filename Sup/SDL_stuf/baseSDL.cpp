#include "baseSDL.h"

void baseSDL::setup(SDL_Renderer ** etrend, SDL_Window ** etwind)
{
     eternal_rend = etrend;
     eternal_window = etwind;
     refresh_pointers();
     grf.setup(etrend,etwind);
}

void baseSDL::refresh_pointers()
{
    current_rend = *(eternal_rend);
    current_window = *(eternal_window);     
}

void baseSDL::SetColorKey(SDL_Color clr)
{
     colorkey = clr;     
}

void baseSDL::DrawSurface(SSurface * surface)
{
     
}

void baseSDL::DrawImage(string path,cords p1,cords p2,SDL_Rect * field_to_draw)
{
	try {
		printf("sukaaa0");
		refresh_pointers();
		printf("sukaaa1");
		SDL_Surface *loadedImage = nullptr;
		SDL_Surface *optsurf = nullptr;
		SDL_Texture *texture = nullptr;
		
		printf("sukaaa2");
		loadedImage = SDL_LoadBMP(path.c_str());
		if(loadedImage == nullptr) throw "ERROR: NO IMAGE FOUND\n";
		
		printf("sukaaa3");
		SDL_SetColorKey(loadedImage,SDL_TRUE,SDL_MapRGB(loadedImage->format,colorkey.r,colorkey.g,colorkey.b));
		optsurf = SDL_ConvertSurface(loadedImage,SDL_GetWindowSurface(current_window)->format,0);
		if(optsurf == nullptr) throw "ERROR: FAILED TO OPTIMIZE SURFACE\n";
		
		
		printf("sukaaa4");
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		rect.w = p2.x - p1.x;
		rect.h = p2.y - p1.y;
   
		SDL_BlitScaled(optsurf,NULL,SDL_GetWindowSurface(current_window),&rect);
		
		printf("sukaaa5");
		texture = SDL_CreateTextureFromSurface(current_rend, optsurf);
		if(texture == nullptr) throw "ERROR: TEXTURE IS EMPTY\n";
		
		printf("sukaaa6");
		SDL_Rect pos;
		pos.x = p1.x;
		pos.y = p1.y;
		pos.w = p2.x - p1.x;
		pos.h = p2.y - p1.y;
		//SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
		SDL_RenderCopy(current_rend, texture, field_to_draw, &pos);
   
		printf("sukaaa7");
		SDL_DestroyTexture( texture );
		Surface_hand del1(loadedImage);
		Surface_hand del2(optsurf);
	}
	catch(const char* eror) { printf(eror); }
}

void baseSDL::DrawImage(string path, cords p1, cords p2)
{
try {
   refresh_pointers();
   SDL_Surface *loadedImage = nullptr;
   SDL_Surface *optsurf = nullptr;
   SDL_Texture *texture = nullptr;
   loadedImage = SDL_LoadBMP(path.c_str());
   if(loadedImage == nullptr) throw "ERROR: NO IMAGE FOUND\n";


   SDL_SetColorKey( loadedImage,SDL_TRUE,SDL_MapRGB(loadedImage->format,colorkey.r,colorkey.g,colorkey.b));
   optsurf = SDL_ConvertSurface(loadedImage,SDL_GetWindowSurface(current_window)->format,0);
	if(optsurf == nullptr) throw "ERROR: FAILED TO OPTIMIZE SURFACE\n";
   
   SDL_Rect rect;
   rect.x = 0;
   rect.y = 0;
   rect.w = p2.x - p1.x;
   rect.h = p2.y - p1.y;
   
   SDL_BlitScaled(optsurf,NULL,SDL_GetWindowSurface(current_window),&rect);
   
   
   if (optsurf != 0){
       texture = SDL_CreateTextureFromSurface(current_rend, optsurf);
   }
   
   SDL_Rect pos;
   pos.x = p1.x;
   pos.y = p1.y;
   pos.w = p2.x - p1.x;
   pos.h = p2.y - p1.y;
   //SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
   SDL_RenderCopy(current_rend, texture, NULL, &pos);
   
   SDL_DestroyTexture( texture );
   Surface_hand del1(loadedImage);
   Surface_hand del2(optsurf);
}
catch(const char* er) { /*printf(er);*/ }
}

void baseSDL::DrawLine(cords p1, cords p2, SDL_Color clr)
{
     grf.Line(p1,p2,clr);
}

void baseSDL::DrawOutRect(cords p1, cords p2, SDL_Color clr)
{
	SDL_SetRenderDrawColor( current_rend, clr.r,clr.g,clr.b,clr.a );
    grf.baseSquare(p1,p2,clr);
}

void baseSDL::DrawFillRect(cords p1, cords p2, SDL_Color clr)
{
    refresh_pointers();
    SDL_Rect fillRect = { p1.x, p1.y, (p2.x-p1.x), (p2.y-p1.y) };
    SDL_SetRenderDrawColor( current_rend, clr.r, clr.g, clr.b, clr.a );
    SDL_RenderFillRect( current_rend, &fillRect );     
}

void baseSDL::DrawDoubleRect(cords p1, cords p2, SDL_Color c1,SDL_Color c2)
{
    DrawFillRect(p1,p2,c1);
    DrawOutRect(p1,p2,c2);
}

void baseSDL::DrawText(string text, cords pos, SDL_Color clr, int big)
{
     //cout << text << endl;
    TTF_CloseFont(Sans);
    Sans = nullptr;
    Sans = TTF_OpenFont("ExtraBold.ttf",big);
    current_rend = *eternal_rend;
    setlocale(LC_ALL, "Russian");
    SDL_Surface* surfaceMessage = NULL;
    SDL_Texture* Message = NULL;
    
    surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), clr);
    Message = SDL_CreateTextureFromSurface(current_rend, surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = pos.x;
    Message_rect.y = pos.y;
    Message_rect.w = 10;
    Message_rect.h = 10;

    SDL_QueryTexture(Message, NULL, NULL, &Message_rect.w, &Message_rect.h);
    SDL_RenderCopy(current_rend, Message, NULL, &Message_rect);
    
    Surface_hand DEL1(surfaceMessage);
    SDL_DestroyTexture(Message);     
}

void baseSDL::SDLprint(string text, SSDLTextParam text_param,cords pos,SDL_Color clr,int tsize)
{
    current_rend = *eternal_rend;
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
    this->DrawText(text,pos,clr,tsize);     
}
