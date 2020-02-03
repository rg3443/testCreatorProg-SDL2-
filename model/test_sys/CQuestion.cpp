#include "CQuestion.h"

CQuestion::CQuestion(int id, string text)
{
	this->create(id,text);
}

void CQuestion::create(int id, string text)
{
	this->set_id(id);
	this->text = text;
}

void CQuestion::add_answer(string text, bool currect)
{
	int answer_id = answers.size();
	answers.push_back(CAnswer(answer_id,text,currect));
}

bool CQuestion::check_answer(int answer_id)
{
	return answers[answer_id].is_currect();
}
