#ifndef CVIEW_H_INCLUDED
#define CVIEW_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "../pcgGlobal.h"
#include "../Sup/QABsys/trueQAB.h"
#include "CKeeper/CKeeper.h"
#include "CDrawer/CDrawer.h"
#include "../Sup/RussianFont/CRussianFont.h"
#include "../Sup/SDL_stuf/OTF_render.h"

class CView {
public:
	CView() {}
	void setup(QAB * qb);
	void draw(int question_id);
	void DrawRect(cords p1,cords p2, SDL_Color clr) { drawer.DrawOutRect(p1,p2,clr); }
	//	self_instruct
	void give_font();
protected:
	QAB * qb;
	CKeeper keeper;
	CDrawer drawer;
	
	//	sup
	OTF_render russian_font_rend;
	CRussianFont russian_font;
};

#endif

