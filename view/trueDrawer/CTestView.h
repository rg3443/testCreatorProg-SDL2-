#ifndef CTESTVIEW_H_INCLUDED
#define CTESTVIEW_H_INCLUDED

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

class CTestView {
public:
	CTestView() {}
	void setup(QAB * qb);
	void present(int question_id);
	void show_question(int question_id);
	void show_results();
	
	void printbutton(string text,cords pos, cords wh, int tex_color_code);
protected:
	baseSDL base_graph_render;
	OTF_render russian_text_render;
	QAB * qb;
};

#endif // CTESTVIEW_H_INCLUDED
