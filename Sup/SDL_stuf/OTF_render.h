#ifndef OTF_RENDER_H_INCLUDED
#define OTF_RENDER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <string>
#include <sstream>
using namespace std;
#include "SDL.h"
#include "SDL_ttf.h"
#include "cGraf.h"
#include "baseSDL.h"
#include "Surface_hand.h"
#include "../../pcgGlobal.h"
#include "GSDL.h"
#include "../QABsys/trueQAB.h"

#include "../RussianFont/CRussianFont.h"

enum EColors {
	WHITE, BLACK
};

const int SYMSIZE = 225;
class OTF_render {
public:
	OTF_render() {  }
	void setup(QAB * qb);
	void DrawRusText_w(string text, cords pos, int size,int color);
	void DrawOtfText(string text, cords pos, int size, int color);
	void DrawSheetText(string text,cords pos, int size);
protected:
	int line_lenght;
	string sheet_path;

	CRussianFont rus_font;
	QAB * qb;
	baseSDL cast;
};

inline void check_quit(SDL_Event * e, bool * quit)
{
	if(e->type == SDL_QUIT) *quit = true;
}

inline void OTF_test(SDL_Renderer ** render,QAB * qb)
{
	SDL_Renderer * rend = *render;
	int xpos = 10;
    OTF_render otfcast;
	otfcast.setup(qb);
	SDL_Event e;
	bool quit = false;
	while(!quit)
	{
		SDL_SetRenderDrawColor(rend,255,255,245,0);
		SDL_RenderClear(rend);
		
		baseSDL cast;
		cast.setup(qb->get_etrnd(), qb->get_etwnd());
		//cast.DrawImage("misc/ALF/s2.bmp",cords(10,10),cords(20,20));
		
		//otfcast.DrawOtfText("в",cords(10,10),50);
		//otfcast.DrawSheetText("абвгдежзиклмнопрстуфхцчшщьэюя",cords(xpos,70),16);
		//otfcast.DrawSheetText("проверка номер один",cords(xpos,10),60);
		otfcast.DrawOtfText("проверка номер два",cords(xpos,10),16, BLACK);
		
		SDL_RenderPresent(rend);
		
		if(SDL_WaitEvent(&e) != 0)
		{
			check_quit(&e,&quit);
		    if(e.type == SDL_MOUSEBUTTONDOWN)
		    {
                xpos += 10;
            }
		}
	}
}

#endif
