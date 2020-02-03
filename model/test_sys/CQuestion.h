#ifndef CQUESTION_H_INCLUDE
#define CQUESTION_H_INCLUDE

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "../../pcgGlobal.h"
#include "BaseModelObject.h"
#include "CAnswer.h"

class CQuestion : public BaseModelObject {
public:
	CQuestion() {}
	CQuestion(int id, string text);
	void create(int id, string text); //	SOZDAT VOPROS
	void add_answer(string text, bool currect);
	
	bool check_answer(int answer_id);
	int answer_size() { return answers.size(); }
	string get_text() { return text; }
	
	CAnswer* get_answer(int answer_id) { return &answers[answer_id]; }
	
protected:
	string text;
	vector<CAnswer> answers;
};

#endif
