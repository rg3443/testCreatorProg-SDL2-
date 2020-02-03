#ifndef CMODEL_H_INCLUDED
#define CMODEL_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "../pcgGlobal.h"
#include "../Sup/QABsys/trueQAB.h"
#include "test_sys/CTest.h"
#include "test_sys/CTestRules.h"

class CModel {
public:
	CModel(){ show_results_time = false; }
	void setup(QAB * qb);
	void check_answer(int qid, int aid);
	CTest* get_test() { return &test; }

	int get_current_question() { test.get_current_question(); }
	void set_current_question(int id) { test.set_current_question(id); }
	// test lead
	bool is_show_results_time() { return show_results_time; }
	
	int get_ammount_questions() { return proverka.get_ammount_questions(); }
	int get_currect_answers() { return proverka.get_current_points(); }
	int get_minimum_currect_answers() { return proverka.get_minimum_points(); }
	bool is_test_passed() { return proverka.is_test_passed(); }
	bool is_test_done() { return proverka.is_test_done(); }
protected:
    CTest test;
	CTestRules proverka;
	QAB * qb;
	
	bool show_results_time;
};

#endif
