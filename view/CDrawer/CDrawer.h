#ifndef CDRAWER_H_INCLUDED
#define CDRAWER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "../../pcgGlobal.h"
#include "../../Sup/SDL_stuf/baseSDL.h"
#include "../../Sup/SDL_stuf/OTF_render.h"
#include "../../Sup/SDL_stuf/CGraf.h"

#include "../CKeeper/CKeeper.h"


class CDrawer : public baseSDL {
public:
	CDrawer() {}
	void insert_qab(QAB * qb) { this->qb = qb; }
	void draw(int question_id,CModel * model);
	
	void draw_question(int question_id,CModel * model);
	void draw_results( CModel * model );
	
	void set_font(CRussianFont * font) { rus_font = font; }
	void set_otf_render(OTF_render * render) { rusrend = render; }
	// self_instructions
	void printbutton(string text, cords pos, cords wh,int button_code,int tex_color_code);
	void test_func();
protected:
	
	//support class
	//View graf;
	QAB * qb;
	OTF_render * rusrend;
	
	CRussianFont * rus_font;
};

#endif
