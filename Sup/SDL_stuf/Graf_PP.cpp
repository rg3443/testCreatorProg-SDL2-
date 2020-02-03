#include "Graf_PP.h"


///////	SETUPS
void Graf_PP::setup( SDL_Window * window, SDL_Renderer * renda )
{
	cast.setup(renda);
	graf.setup(renda,window);
}
///////	LIST
void Graf_PP::lista( int x,int y, int stolb,int lines, int pix_w, int pix_h )
{
    log.open("Logs\\log_line_coords.txt");
    log.write("|||  ГОРИЗОНТАЛЬНЫЕ ЛИНИИ  |||\n");
	int current_pos_x = x;
	int current_pos_y = y;
	for(int line=0;line<lines;line++)
	{
		cords p1,p2;
		p1.x = current_pos_x;
		p1.y = current_pos_y;
		p2.x = stolb * pix_w;
		p2.y = current_pos_y;
		//
		string rez = ccint(p1.x,p1.y,p2.x,p2.y);
		log.write( rez.c_str() );
		rez = peremen("line# : ",line);
		log.write( rez.c_str() );
		//
		graf.Line(p1,p2,d_color);
		current_pos_y = current_pos_y + pix_h;
	}
	log.write("|||  ВЕРТИКАЛЬНЫЕ ЛИНИИ  |||\n");
	 current_pos_x = x;
	 current_pos_y = y;
	for(int stb=0;stb<stolb;stb++)
	{
		cords p1,p2;
		p1.x = current_pos_x;
		p1.y = current_pos_y;
		p2.x = current_pos_x;
		p2.y = lines * pix_h;
		//
		string rez = ccint(p1.x,p1.y,p2.x,p2.y);
		log.write( rez.c_str() );
		rez = peremen("stolb# : ",stb);
		log.write( rez.c_str() );
		//
		graf.Line(p1,p2,d_color);
		current_pos_x = current_pos_x + pix_w;
	}
}


////////

/*void Graf_PP::pad_mat(int ampad_x,int ampad_y,int x,int y, int w,int h,int pix_ot_w, int pix_ot_h)
{
	cords p1,p2;
	int current_pos_x = x;
	int current_pos_y = y;
	for(int verti=0;verti<ampad_x;verti++)
	{
		for(int horiz=0;horiz<ampad_y;horiz++)
		{
			p1.x = current_pos_x;
			p1.y = current_pos_y;
			graf.baseSquare();
			current_pos_x = current_pos_x + w + pix_ot_w;
		}
		current_pos_x = x;
		current_pos_y = current_pos_y + h + pix_ot_h;
	}
}*/