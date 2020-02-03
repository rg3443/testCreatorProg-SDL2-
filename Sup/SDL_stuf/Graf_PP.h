#ifndef GRAF_PP_H_INCLUDED
#define GRAF_PP_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <vector>
#include <thread>
#include <sstream>
#include <string>
#include "SDL.h"
#include "cGraf.h"
#include "customSDL.h"
using namespace std;

#include "../Logs/cLog.h"
string ccint(int x1,int y1, int x2, int y2)
{
    string all_data;
    string s[4];
    s[0] = std::to_string(x1);
    s[1] = std::to_string(y1);
    s[2] = std::to_string(x2);
    s[3] = std::to_string(y2);
    all_data = "x1 : " + s[0] +"| y1  : " + s[1] + "| x2 :" + s[2] + "| y2 : " + s[3] + "\n";
    return all_data;
}
string peremen(const char* text,int x)
{
    string buf;
    buf = to_string(x);

    string rez = text + buf + "\n";
}
class Graf_PP {
public:
	Graf_PP() {}
	void setup(SDL_Window * window, SDL_Renderer * renda);
	void set_draw_color(SDL_Color clr) { d_color = clr; }

	void test_line(cords p1, cords p2) { graf.Line(p1,p2, Red); }

	//	LIST
	void lista( int x,int y, int stolb,int lines, int pix_w, int pix_h);
	void vertical_lines(int x,int y, int stolb,int lines, int pix_w, int pix_h);
	void horizontal_lines(int x,int y, int stolb,int lines, int pix_w, int pix_h);

	void pad_mat(int ampad_x,int ampad_y,int x,int y, int w,int h,int pix_ot_w, int pix_ot_h) {}
protected:
	View graf;
	customSDL cast;
	SDL_Color d_color;

	Logys log;
};

#endif // GRAF_PP_H_INCLUDED
