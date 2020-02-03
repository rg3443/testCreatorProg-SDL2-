#include "CTest.h"

void CTest::add_question(string text)
{
	int question_id = questions.size();
	questions.push_back(CQuestion(question_id,text));
}

void CTest::add_answer(int question_id, string text, bool currect)
{
	try {
		if(question_id < questions.size())
			questions[question_id].add_answer(text,currect);
		else 
			throw "ERROR:(code:1) QUESTION_ID IS MORE THAN QUESTION_SIZE\n";
	}
	catch(const char* eror) { printf(eror); }
}

bool CTest::check_answer(int question_id, int answer_id)
{
	//current_question_id++;
	try {
		if(question_id < questions.size())
			return questions[question_id].check_answer(answer_id);
		else 
			throw "ERROR:(code:2) QUESTION_ID IS MORE THAN QUESTION_SIZE\n";
	}
	catch(const char* eror) { printf(eror); return false; }
}

CQuestion* CTest::get_question(int question_id)
{
	try {
		if(question_id < questions.size())
			return &questions[question_id];	
		else 
			throw "ERROR:(code:3) QUESTION_ID IS MORE THAN QUESTION_SIZE\n";
	}	
	catch(const char* eror) { printf(eror); }
}
