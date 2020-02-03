#ifndef PCGGLOBAL_H_INCLUDED
#define PCGGLOBAL_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <sstream>
//#include <thread>
//#include <mutex>
#include <string>
using namespace std;
#include "SDL.h"
#include "Windows.h"
//#include "SDL_ttf.h"
 //int SCREEN_H = 150;
// int SCREEN_W = 300;

#define nullptr NULL
static SDL_Renderer * renderera=0;
static SDL_Window * windowa=0;
inline SDL_Renderer* get_rnd() { return renderera; }
inline SDL_Window* get_wnd() { return windowa; }
inline bool is_active() { if(renderera==0) return false; else return true; }



struct cords {
       int x,y;
       cords() {}
       cords(const cords & crd) { x = crd.x; y = crd.y; }
       cords(int nx,int ny) { x = nx; y = ny; }
       void setcord(int nx, int ny) { x = nx; y = ny; }
};

struct fcords {
       float x,y;
       fcords() {}
       fcords(float nx, float ny) { x = nx; y = ny; }
       void setcord(float nx,float ny) { x = nx; y = ny; }        
};

inline bool operator==(const cords & crd1,const cords & crd2)
{
    if(crd1.x == crd2.x && crd1.y == crd2.y)
        return true;
    else 
        return false;     
}

enum Enemys_id {
     BOMJ

};
/*
enum SRCH_TYPES {
    NOTHING=0,
    NEAR=1,
    EAT=2
};
*/
enum Directions {
    UP=1,DOWN=2,LEFT=3,RIGHT=4,
    CHILL=5
};

inline int opositdir(int direction)
{
    switch(direction)
    {
   	case UP:
	     return DOWN;
    break;
	case DOWN:
	     return UP;
    break;
	case LEFT:
	     return RIGHT;
    break;
	case RIGHT:
	     return LEFT;
    break;                 
    }    
}

enum EButton_types {
	REDBUTT, 
	YELLOWBUTT,
	GHOSTBUTT
};


inline void inccords(int x, int y, cords * crd) { crd->x = x; crd->y = y; }

inline cords is_in(cords p1, cords p2, cords p3)
{
    if(p3.x > p1.x && p3.x < p2.x && p3.y > p1.y && p3.y < p2.y) return p3;
    else { cords negative(-1,-1); return negative; }
}


class CEnemy;
class CNPC;
class baseItem;
class baseInterer;
enum Object_types {
    ENEMY,
    NPC,
    ITEM,
    INTERER
};
struct SObject_type {
	CEnemy* enemy_type;
	CNPC* npc_type;
	baseItem* item_type;
	baseInterer* interer_type;
};


//inline TTF_Font* get_sans() { return Sans; }
//struct cords {int x,y;};
//TEXT LOADING AND DRAW
//TTF_Font* Italic = TTF_OpenFont("BoldItalic.ttf", 24); //sans
//TTF_Font* Ruslan = TTF_OpenFont("coolrus.otf", 24);
static SDL_Color White = {255, 255, 255};// white
static SDL_Color Black = {0, 0, 0};        //black
static SDL_Color Dark = {67, 68, 69};    // dark grey
static SDL_Color Dark2 = {34, 34, 34};    // dark grey
static SDL_Color Grey = {187, 191, 194}; // light grey
static SDL_Color Red = {255, 0, 0};      // red
static SDL_Color Green = {0, 255, 0};    // green
static SDL_Color Blue = {0, 0, 255};     // blue
static SDL_Color Yellow = {255,255,0}; //yellow
static SDL_Color Cool = { 0,100,100 }; //cool

static SDL_Color backgr = Grey;

inline SDL_Color get_white() { return White; }
inline SDL_Color get_black() { return Black; }
inline SDL_Color get_yellow() { return Yellow; }
inline SDL_Color get_green() { return Green; }

inline SDL_Color typecolor(int r,int g,int b)
{
    SDL_Color clr = { r,g,b };
    return clr;
}

inline SDL_Rect typerect(cords p1, cords wh)
{
	SDL_Rect rect;
	rect.x = p1.x;
	rect.y = p1.y;
	rect.w = wh.x;
	rect.h = wh.y;
	return rect;
}

inline void printmemory()
{
   MEMORYSTATUS ms;
   GlobalMemoryStatus(&ms);
   cout << "START MEMORY: " << (ms.dwTotalPhys / 1024 / 1024) << " mb" << endl;
   cout << "LEFT MEMORY: " << (ms.dwAvailPhys / 1024 / 1024) << " mb" << endl;
}

inline void setrenderdrawcolor(SDL_Renderer* rend, SDL_Color clr)
{
    SDL_SetRenderDrawColor(rend,clr.r,clr.g,clr.b,clr.a);
}
template<typename T>
inline string to_string(T value)
{
    stringstream ss;
    ss << value;
    string buf = ss.str();
    return buf;       
}

template<typename T>
inline int to_int(T value)
{
    stringstream ss;
    ss << value;
    int buf;
    ss >> buf;
    return buf;
}

template<typename T>
inline float to_float(T value)
{
    stringstream ss;
    ss << value;
    float buf;
    ss >> buf;
    return buf;       
}

template<typename T>
inline void mnojim(T * value, float proc)
{
     stringstream ss;
     ss << *(value);
     float rez;
     ss >> rez;
     rez = rez / proc;
     stringstream afterpart;
     afterpart << rez;
     afterpart >> *(value);
}

inline int mnojim(int value, float proc)
{
       printf("\t PROCENT IS %f\nDO %d \t", proc, value);
    stringstream ss;
    ss << value;
    float buf;
    ss >> buf;
    int rez = to_int( to_float(value) * proc );
    printf("POSLE %d \n", rez);
    return rez;       
}

#endif // PCGGLOBAL_H_INCLUDED
