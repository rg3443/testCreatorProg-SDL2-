#include "CAnswer.h"

CAnswer::CAnswer(int id, string text, bool currect)
{
	this->create(id,text,currect);
}

void CAnswer::create(int id, string text, bool currect)
{
	this->set_id(id);
	this->text = text;
	this->currect = currect;
}
