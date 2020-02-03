#ifndef CTESTRULES_H_INCLUDED
#define CTESTRULES_H_INCLUDED

class CTestRules {
public:
	CTestRules() {}
	void setup(int ammount_questions, int minimum_points);
	
	void add_answer_status(bool is_currect);
	
	bool is_test_done();
	bool is_test_passed();
	
	int get_ammount_questions() { return ammount_questions; }
	int get_minimum_points() { return minimum_points; }
	int get_current_points() { return current_points; }
	
protected:
	int ammount_questions;
	int minimum_points;
	int current_points;
	
	int question_iterator;;
};

#endif
