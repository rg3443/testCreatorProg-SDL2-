#ifndef TTF_RENDER_H_INCLUDED
#define TTF_RENDER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
#include "SDL.h"
#include "SDL_ttf.h"
//#include "SDL_image.h"
//#include "gGlobal.h"
#include "cGraf.h"
#include "../../pcgGlobal.h"
#include "../../Sup/QABsys/trueQAB.h"
//template<class T>
class TTF_render {
public:
    TTF_render() {}
    void seetup(QAB* qb);
    void DrawText(int x,int y,SDL_Color clr, const char* text,int big);
    void DrawPeremen(int x,int y,SDL_Color clr,const char* text, int big);   
protected:
    QAB * qb;
          
};

#endif
