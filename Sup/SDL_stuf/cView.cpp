#include "cGraf.h"

//base func
void View::Line(cords p1, cords p2,SDL_Color c)
{
    renderer = *eternal_renderer;
    window = *eternal_window;
    //SDL_SetRenderDrawColor( renderer, c.r, c.g, c.b,c.a);
    SDL_RenderDrawLine( renderer, p1.x, p1.y, p2.x, p2.y );
}

void View::baseShit(cords p1, cords p4, SDL_Color c)
{
    cords p2(p4.x,p1.y);
    cords p3(p1.x,p4.y);

    Line(p1,p2,c);
    Line(p2,p3,c);
    Line(p3,p4,c);
    Line(p4,p1,c);

}

void View::baseSquare(cords p1, cords p4, SDL_Color clr)
{
    cords p2;
    p2.x = p4.x;
    p2.y = p1.y;

    cords p3;
    p3.x = p1.x;
    p3.y = p4.y;

    Line(p1,p2,clr);
    Line(p2,p4,clr);
    
    Line(p3,p1,clr);
}

void View::fillSquare(cords p1, cords p4, SDL_Color clr)
{

    renderer = *eternal_renderer;
    SDL_Rect fillRect;
    fillRect.x = p1.x;
    fillRect.y = p1.y;
    fillRect.w = p4.x - p1.x;
    fillRect.h = p4.y - p1.y;
    SDL_SetRenderDrawColor( renderer, clr.r, clr.g, clr.b, 0 );
    SDL_RenderFillRect( renderer, &fillRect );

}

void View::fillSquare(int x,int y,int w,int h,SDL_Color clr)
{
    renderer = *eternal_renderer;
                    SDL_Rect fillRect;
                    fillRect.x = x;
                    fillRect.y = y;
                    fillRect.w = w;
                    fillRect.h = h;
                    SDL_SetRenderDrawColor( renderer, clr.r, clr.g, clr.b, 0 );
                    SDL_RenderFillRect( renderer, &fillRect );
                     //SDL_SetRenderDrawColor( renderer, 0,0,0,0 );
}

void View::baseCircle(cords p_centre, int diametr, SDL_Color clr)
{
	//scan 4 points
	vector< vector<cords> > points;//[4];
	points.resize(4);
	for(int j=0;j<4;j++) points[j].resize(diametr);

	cords RX((p_centre.x + diametr),p_centre.y);
	cords LX((p_centre.x - diametr),p_centre.y);
	cords DY(p_centre.x,(p_centre.y + diametr));
	cords UY(p_centre.x,(p_centre.y - diametr));
	for(int i1=0;i1<diametr;i1++)
	{
		cords new_p1((RX.x-i1),(RX.y+i1));
		points[0].push_back(new_p1);
	}
	for(int i2=0;i2<diametr;i2++)
	{
		cords new_p2((DY.x-i2),(DY.y-i2));
		points[1].push_back(new_p2);
	}
	for(int i3=0;i3<diametr;i3++)
	{
		cords new_p3((LX.x+i3),(LX.y-i3));
		points[2].push_back(new_p3);
	}
	for(int i4=0;i4<diametr;i4++)
	{
		cords new_p4((UY.x+i4),(UY.y+i4));
		points[1].push_back(new_p4);
	}

	for(int part=0;part<4;part++)
	{
		for(int np=0;np<diametr;np++)
		{
			//if((np+1) < diametr)
				Line(points[part][np],points[part][np+1],clr);
				/*
			else
			{
				if(part == RX) Line(points[part][np],RX);
				else if(part == DY) Line(points[part][np],DY);
				else if(part == LX) Line(points[part][np],LX);
				else if(part == UY) Line(points[part][np],UY);
			}*/
		}
	}
}

