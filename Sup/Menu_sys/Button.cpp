#include "Button.h"

void Button::setup(int x,int y,int w,int h,int place,int dir, string text)
{
	this->crd.x = x;
	this->crd.y = y;
	this->w = w;
	this->h = h;
	this->text = text;
	status.place = place;
	status.direct = dir;
}

base_status Button::check_click(int mx,int my)
{
	if(mx > crd.x && mx < (crd.x+w) && my > crd.y && my < (crd.y+h))
	{
		status.active = true;
		return status;
	}
	else
	{
		status.active = false;
		return status;
	}
}
