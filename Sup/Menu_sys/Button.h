#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED


#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include "../QABsys/trueQAB.h"
using namespace std;

struct base_line {
	cords p[2];
};

struct base_text {
	cords point;
	string symbols;
};

struct base_status {
	int place;
	int direct;
	bool active;
};

class Button {
public:
	Button(){}
	void setup(int x,int y,int w,int h,int place,int dir, string text);
	base_status check_click(int mx,int my);

	string get_text() { return text; }

	int get_x() { return crd.x; }
	int get_y() { return crd.y; }
	cords get_xy() { return crd; }
	int get_w() { return w; }
	int get_h() { return h; }

protected:
	base_status status;
	string text;
	cords crd;
	int w,h;
};


#endif // BUTTON_H_INCLUDED
