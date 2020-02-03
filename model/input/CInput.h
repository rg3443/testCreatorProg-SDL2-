#ifndef CINPUT_H_INCLUDED
#define CINPUT_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "../../Sup/QABsys/trueQAB.h"
#include "../../pcgGlobal.h"

#include "../CModel.h"
#include "SDL.h"
#include "SDL_ttf.h"

class CInput {
public:
	CInput() {}
	void setup(CModel * model);
	void check_input(bool * is_quit);
protected:
	SDL_Event e;
	CModel* model;
	
    //SUPPORT
    int w,h;
    cords pos;
};

#endif
