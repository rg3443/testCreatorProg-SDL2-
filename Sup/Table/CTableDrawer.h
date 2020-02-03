#ifndef CTABLEDRAWER_H_INCLUDED
#define CTABLEDRAWER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
#include "SDL.h"
#include "SDL_ttf.h"

#include "../SDL_stuf/customSDL.h"
#include "../SDL_stuf/cGraf.h"
#include "../SDL_stuf/Surface_hand.h"
#include "../SDL_stuf/Viewport.h"

#include "CTable.h"

class CTableDrawer {
public:
    CTableDrawer() {}
    CTableDrawer(QAB * qb,CTable * table,cords pos, int tw , int th, SDL_Color clr);
    void setup(QAB * qb);
    void draw_table(CTable * table,cords pos, int tw , int th, SDL_Color clr);

protected:
    QAB * qb;
    customSDL cast;
    View grf;

};

#endif // CTABLEDRAWER_H_INCLUDED
