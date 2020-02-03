#ifndef CSTOLB_H_INCLUDED
#define CSTOLB_H_INCLUDED

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

struct SType {
    float value;
    string text;
    SType() {}
    SType(float nvalue,string ntext) {
        value = nvalue;
        text = ntext;
    }
    bool is_value() {
        if(value != -1)
            return true;
        else
            return false;
    }
    bool is_text() {
        if(text.c_str() != "NULL")
            return true;
        else if(text.c_str() == "NULL")
            return false;
    }
};

class CStolb {
public:
    CStolb() {}
    void setup(QAB * qb, int ammount_tiles);
    void set_name(string name) { this->name = name; }
    void insert_data(SType value, int tile_id);
    void add_data(SType data);

    string* get_name() { return &name; }
    SType* get_data(int tile_id) { return &tile[tile_id]; }
    int size() { return tile.size(); }

protected:
    QAB * qb;
    string name;
    vector<SType> tile;

};

#endif // CSTOLB_H_INCLUDED
