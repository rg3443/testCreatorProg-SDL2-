#include "CRussianFont.h"

void CRussianFont::init()
{
	const int SYBMOL_AMMOUNT = 32;
	symbol_fields.resize(SYBMOL_AMMOUNT);
	cords p1,wh;
	p1.x = 0;
	p1.y = 0;
	wh.x = 15;
	wh.y = 21;
	//	SHIT INIT
	for(int i=0;i<SYBMOL_AMMOUNT;i++)
	{
		symbol_fields[i] = typerect(p1,wh);
		p1.x += wh.x;
		
		int x,y,w,h;
		x = symbol_fields[i].x;
		y = symbol_fields[i].y;
		w = symbol_fields[i].w;
		h = symbol_fields[i].h;
		printf("STATUS : RUSS FONT SYMBOL #%d : POS-X%d-Y%d|SIZE-W%d-H%d\n", i,x,y,w,h);
	}
	
	//	SEPARATE INIT
	alfavit.resize(32);
	for(int i=0;i<alfavit.size();i++)
	{
		alfavit[i].set_id(i);
	}
	
	
}

SDL_Rect* CRussianFont::get_rect_by_symbol(char sym)
{
	int sym_id;
		switch(sym)
		{
		case 'à':
		//printf("\tSTATUS : DRAWS #%d SYMBOL\n",symid);
			sym_id = 0;
		break;
		case 'á':
			sym_id = 1;
		break;
		case 'â':
			sym_id = 2;
		break;
		case 'ã':
			sym_id = 3;
		break;
		case 'ä':
			sym_id = 4;
        break;
		case 'å':
			sym_id = 5;
        break;
		case 'æ':
			sym_id = 6;
        break;
		case 'ç':
			sym_id = 7;
        break;
		case 'è':
			sym_id = 8;
        break;
		case 'é':
			sym_id = 9;
        break;
		case 'ê':
			sym_id = 10;
        break;
		case 'ë':
			sym_id = 11;
        break;
		case 'ì':
			sym_id = 12;
        break;
		case 'í':
			sym_id = 13;
        break;
		case 'î':
			sym_id = 14;
        break;
		case 'ï':
			sym_id = 15;
        break;
		case 'ð':
			sym_id = 16;
        break;
		case 'ñ':
			sym_id = 17;
        break;
		case 'ò':
			sym_id = 18;
        break;
		case 'ó':
			sym_id = 19;
        break;
		case 'ô':
			sym_id = 20;
        break;
		case 'õ':
			sym_id = 21;
        break;
		case 'ö':
			sym_id = 22;
        break;
		case '÷':
			sym_id = 23;
        break;
		case 'ø':
			sym_id = 24;
        break;
		case 'ù':
			sym_id = 25;
        break;
		case 'ú':
			sym_id = 26;
		break;
		case 'û':
			sym_id = 27;
		break;
		case 'ü':
			sym_id = 28;
        break;
		case 'ý':
			sym_id = 29;
        break;
		case 'þ':
			sym_id = 30;
        break;
		case 'ÿ':
			sym_id = 31;
        break;
		}		
	return &symbol_fields[sym_id];
}

SDL_Rect* CRussianFont::get_rect_by_symbol_id(int sym_id)
{
	return &symbol_fields[sym_id];
}
