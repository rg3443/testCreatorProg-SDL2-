#ifndef CTABLE_H_INCLUDED
#define CTABLE_H_INCLUDED

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
#include "../SDL_stuf/cGraf.h"
#include "../SDL_stuf/Surface_hand.h"
#include "../../pcgGlobal.h"
#include "../QABsys/trueQAB.h"

#include "CStolb.h"

class CTable {
public:
    CTable() {}
    void setup(QAB * qb,int w,int h);
    void set_stolb_name(int stid, string name);
    void set_strok_name(int stid, string name);
    void insert_data(SType data, cords pos);
    void add_data(SType data, string columnname);

    string get_stolb_name(int id) { return *(stolb[id].get_name()); }
    string get_strok_name(int id) {return strok_name[id];}
    SType get_data(cords pos);
    int stolb_size() { return stolb.size(); }
    int strok_size() { return stolb[0].size(); }
protected:
    QAB * qb;
    vector<CStolb> stolb;
    vector<string> strok_name;
};

#endif // CTABLE_H_INCLUDED
