#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <sstream>
#include "../QABsys/trueQAB.h"
using namespace std;
#include "Button.h"
//#include "../../Model/base_Model/Model_sys.h"

struct base_menu_data {
	vector<Button> butt;
	vector<base_line> lines;
	vector<base_text> texts;
};

class Menu {
public:
	Menu() {}
	void setup(QAB* qb,int name);
	int get_name() { return name.place; }
	void add_button(int x,int y,int w,int h,int place,int dir,const char* text);
	base_menu_data get_data() { data.butt=butt;data.lines=lines;data.texts=texts;return data; }
protected:
	vector<Button> butt;
	vector<base_line> lines;
	vector<base_text> texts;
	base_status name;
	int name2;
	base_menu_data data;
	QAB* qb;
};

#endif // MENU_H_INCLUDED
