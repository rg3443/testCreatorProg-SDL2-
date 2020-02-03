#include "OTF_render.h"

void OTF_render::setup(QAB * qb)
{
	this->qb = qb;
	cast.setup(qb->get_etrnd(),qb->get_etwnd());
	cast.SetColorKey(typecolor(255,255,255));
	rus_font.init();
	sheet_path = rus_font.get_sheet_path();
}

void OTF_render::DrawSheetText(string text,cords pos, int size)
{
	 int SIZEW = size;
	 int SIZEH = size;
    setlocale(LC_ALL, "Russian");
	int smeshx = 0;
	int smeshy = 0;
	string buf;
	for(int symid=0;symid<text.size();symid++)
	{
		SDL_Rect * symbol_field = rus_font.get_rect_by_symbol(text[symid]);
		cast.DrawImage(sheet_path,pos,cords(pos.x+SIZEW,pos.y+SIZEH),symbol_field);
		
		pos.x += size;
		
	}
}

void OTF_render::DrawOtfText(string text, cords pos, int size, int color)
{
	
	string buf;
	for(int symid=0;symid<text.size();symid++)
	{
        if(text[symid] != ' ') {
		    buf = text[symid];
		    this->DrawRusText_w(buf,pos,size,color);
        }
		pos.x += size;
	}
}

void OTF_render::DrawRusText_w(string text, cords pos,int size,int color)
{
	/*
		class using 2 directories : misc/ALF & misc/ALFWHITE
		all letters have same name in different colors (.../s#.bmp)
	*/
	
	string sym,bufString;
	 int SIZEW = size;
	 int SIZEH = size;
    setlocale(LC_ALL, "Russian");
	string path,last_direction;
	path = "misc\\ALF\\";
	
	stringstream type_changer_xd;
	type_changer_xd << text;
	char symbol;
	type_changer_xd >> symbol;
	
    int smeshx = 0;
	int smeshy = 0;
	bool symFound = false;
		switch(symbol)
		{
		case 'à':
			last_direction = "s1.bmp";
			path = path + last_direction;
			symFound = true;
		break;
		case 'á':
			path = path + "s2.bmp";
			symFound = true;
		break;
		case 'â':
			path = path + "s3.bmp";
			symFound = true;
		break;
		case 'ã':
			path = path + "s4.bmp";
			symFound = true;
		break;
		case 'ä':
			path = path + "s5.bmp";
			symFound = true;
        break;
		case 'å':
			path = path + "s6.bmp";
			symFound = true;
        break;
		case 'æ':
			path = path + "s7.bmp";
			symFound = true;
        break;
		case 'ç':
			path = path + "s8.bmp";
			symFound = true;
        break;
		case 'è':
			path = path + "s9.bmp";
			symFound = true;
        break;
		case 'é':
			path = path + "s10.bmp";
			symFound = true;
        break;
		case 'ê':
			path = path + "s11.bmp";
			symFound = true;
        break;
		case 'ë':
			path = path + "s12.bmp";
			symFound = true;
        break;
		case 'ì':
			path = path + "s13.bmp";
			symFound = true;
        break;
		case 'í':
			path = path + "s14.bmp";
			symFound = true;
        break;
		case 'î':
			path = path + "s15.bmp";
			symFound = true;
        break;
		case 'ï':
			path = path + "s16.bmp";
			symFound = true;
        break;
		case 'ð':
			path = path + "s17.bmp";
			symFound = true;
        break;
		case 'ñ':
			path = path + "s18.bmp";
			symFound = true;
        break;
		case 'ò':
			path = path + "s19.bmp";
			symFound = true;
        break;
		case 'ó':
			path = path + "s20.bmp";
			symFound = true;
        break;
		case 'ô':
			path = path + "s21.bmp";
			symFound = true;
        break;
		case 'õ':
			path = path + "s22.bmp";
			symFound = true;
        break;
		case 'ö':
			path = path + "s23.bmp";
			symFound = true;
        break;
		case '÷':
			path = path + "s24.bmp";
			symFound = true;
        break;
		case 'ø':
			path = path + "s25.bmp";
			symFound = true;
        break;
		case 'ù':
			path = path + "s26.bmp";
			symFound = true;
        break;
		case 'ú':
			path = path + "s27.bmp";
			symFound = true;
		break;
		case 'û':
			path = path + "s28.bmp";
			symFound = true;
		break;
		case 'ü':
			path = path + "s29.bmp";
			symFound = true;
        break;
		case 'ý':
			path = path + "s30.bmp";
			symFound = true;
        break;
		case 'þ':
			path = path + "s31.bmp";
			symFound = true;
        break;
		case 'ÿ':
			path = path + "s32.bmp";
			symFound = true;
        break;
		}
		if(!symFound) 
		{
             path = "";
             bufString = symbol;
             cast.DrawText(bufString,cords(pos.x+smeshx,pos.y+smeshy-2),Red,17);              
        }
		//cout << path << endl;
		cast.DrawImage(path,cords(pos.x+smeshx,pos.y+smeshy),cords(pos.x+SIZEW,pos.y+SIZEH));
		smeshx += size;
}
