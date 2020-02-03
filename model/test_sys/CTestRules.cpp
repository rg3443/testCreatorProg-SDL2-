#include "CTestRules.h"

void CTestRules::setup(int ammount_questions, int minimum_points)
{
	this->ammount_questions = ammount_questions;
	this->minimum_points = minimum_points;
	question_iterator = 0;
	current_points = 0;
}

void CTestRules::add_answer_status(bool is_currect)
{
	if(is_currect)
	{
		current_points++;
	}
	question_iterator++;
}

bool CTestRules::is_test_passed()
{
	if(current_points < minimum_points) 
	{
		return true;
	} else {
		return false;
	}
}

bool CTestRules::is_test_done()
{
	if(question_iterator == ammount_questions)
	{
		return true;
	} else {
		return false;
	}
}
