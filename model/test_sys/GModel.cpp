#include "GModel.h"

CQuestion::CQuestion(const CQuestion & to_copy)
{
	//to_copy = *(this);
}

void CQuestion::setup(int id,string text) 
{
	this->id = id;
	question = text;
	
}

void CQuestion::add_answer(int id,string text, bool cur)
{
	printf("\tEWFWFWE222222222222222FWEF2WFE\n");
	answer.push_back(SAnswer(id,text,cur));
	//.setup(id,text,cur);
	printf("\tEWFWFWEF33333333333333333333333333WEF2WFE\n");
}

// answers allready have current/false flags
bool CQuestion::check_currency(int aid)
{
	return answer[aid].curr;
}

/////

void CTest::setup(QAB * qb)
{
	this->qb = qb;
}

void CTest::add_quest(int id, string questtext)
{
	CQuestion new_one;
	new_one.setup(id,questtext);
	this->quest.push_back( new_one );
}

void CTest::add_answ(int qid, string text, int pos,bool curr)
{
	quest[qid].add_answer(pos,text,curr);
}
