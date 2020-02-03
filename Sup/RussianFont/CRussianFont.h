#ifndef CRUSSIANFONT_H_INCLUDED
#define CRUSSIANFONT_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <string>
#include <sstream>
using namespace std;
#include "SDL.h"
#include "SDL_ttf.h"
#include "../../pcgGlobal.h"


class SRussianSym {
private:
	string image_path;
	char symbol_code;
	int id;
public:
	SRussianSym() {}
	SRussianSym(string path,char symbol)
	{
		init(path,symbol);
	}
	void init(string path,char symbol)
	{
		image_path = path;
		symbol_code = symbol;	
	}
	void set_id(int id) { this->id = id; }
	int get_id() { return id; }
	char get_sym() { return symbol_code; }
	string get_path() { return image_path; }
};

class CRussianFont {
public:
	CRussianFont() { sheet_path = "misc/ALF/FULLSANS.bmp"; }
	void init();
	
	SDL_Rect * get_rect_by_symbol(char sym);
	SDL_Rect * get_rect_by_symbol_id(int sym_id);
	
	string get_sheet_path() { return sheet_path; }
	
	
protected:
	string sheet_path;
	vector<SDL_Rect> symbol_fields;
	vector<SRussianSym> alfavit;
	
};

#endif
