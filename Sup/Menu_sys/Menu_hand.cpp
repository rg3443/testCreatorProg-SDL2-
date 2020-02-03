#include "Menu_hand.h"
/*
void Menu_hand::setup(QAB * qb)
{
	this->qb = qb;
}

void Menu_hand::crt_menu(int name)
{
	Menu new_menu;
	new_menu.setup(qb,name);
	menus.push_back(new_menu);
}

void Menu_hand::crt_button(int x,int y,int w,int h,int place,int dir, const char * text)
{
	int id = srch_menu(place);
	menus[id].add_button(x,y,w,h,place,dir,text);
}

void Menu_hand::switch_menu(base_status cl_rez)
{
	if(cl_rez.active)
	{
		// UNICAL BUTTONS
		switch(cl_rez.direct)
		{
		case PLUS_M:
			cout << "PLUS M IS WORKING\n";
		break;
		case MINUS_M:
			cout << "minuS M IS WORKING\n";
		break;
		case PLUS_Y:
			cout << "PLUS y IS WORKING\n";
		break;
		case MINUS_Y:
			cout << "mnus M IS WORKING\n";
		break;
		case HERE_TYPE:
		break;
		case BRON_TYPE:
		break;
		case GIVE_TYPE:
		break;
		case MINUS_AM_SEAL:
		break;
		case PLUS_AM_SEAL:
		break;
		case ACCEPT_SEAL:
		break;
		}
		/*
		if(cl_rez.direct > START_LIGHT_BUTTONS)
		{
			int choosen_day = cl_rez.direct - START_LIGHT_BUTTONS;
		}
		*/
		/*
	}

}

int Menu_hand::srch_menu(int name)
{
	for(int id=0;id<menus.size();id++)
	{
		if(menus[id].get_name() == name)
			return id;
	}
}
*/

