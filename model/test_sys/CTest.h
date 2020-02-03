#ifndef CTEST_H_INCLUDE
#define CTEST_H_INCLUDE

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
#include "CQuestion.h"

class CTest : public BaseModelObject {
public:
	CTest(){ current_question_id = 0; }
	void setup(); 
	void setup_enter();
	void setup_exit();
	
	void add_question(string text);
	void add_answer(int question_id, string text, bool currect);
	
	bool check_answer(int question_id, int answer_id);
	
	int get_current_question() { return current_question_id; }
	void set_current_question(int id) { current_question_id = id; }
	void next_question() { current_question_id++; }
	
	int quest_size() { return questions.size(); }
	
	CQuestion* get_question(int question_id);
protected:
	vector<CQuestion> questions;
	int current_question_id;
};

#endif
