#ifndef MENU_HAND_H_INCLUDED
#define MENU_HAND_H_INCLUDED



#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

#include "../QABsys/trueQAB.h"
using namespace std;

#include "Menu.h"

class Menu_hand {
public:
	Menu_hand(){ active_menu_id = 0; }
	void setup(QAB * qb);
	void crt_menu(int name);
	void crt_button(int x,int y,int w,int h,int place,int dir,const char * text);

	void switch_menu(base_status cl_rez);
	int srch_menu(int name);
	int get_active() { return active_menu_id; }

	base_menu_data get_menu_data(int id) { return menus[id].get_data(); }
protected:
	QAB * qb;
	vector<Menu> menus;
	int active_menu_id;
};

#endif // MENU_HAND_H_INCLUDED
