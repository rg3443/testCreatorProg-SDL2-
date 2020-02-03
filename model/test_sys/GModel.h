#ifndef GMODEL_H_INCLUDE
#define GMODEL_H_INCLUDE

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "../../pcgGlobal.h"
#include "../../Sup/QABsys/trueQAB.h"

//Struct True Answer Counter
struct STAnswCounter {
    vector<bool> answer;
    void setup(int ammount_question) {
        answer.resize(ammount_question);     
    }
    void insert_answ(int question_id,bool curr) {
        answer[question_id] = curr;     
    }    
	bool get_answ(int id) {
		return answer[id];
	}

    
};

struct SAnswer {
    int id;
    bool curr;    
    string text;
    SAnswer(){}
    SAnswer(int aid, string tex, bool cur) {
        id = aid;
        curr = cur;
        text = tex;          
    }   
    void setup(int aid, string tex, bool cur) {
        id = aid;
        curr = cur;
        text = tex;         
	printf("\tEWFWFWEF55555555555555555555555555WEF2WFE\n"); 
    }   
};

class CQuestion {
public:
    CQuestion(){}
    CQuestion(const CQuestion & to_copy);
	CQuestion(int id, string text){ this->setup(id,text); }
    void setup(int id, string text);
    void add_answer(int id,string text, bool cur);
    bool check_currency(int aid);
	
	string get_text() { return question; }
	SAnswer* get_answer(int aid) { return &answer[aid]; }
	
	int answer_size() { return answer.size(); }
	void set_answers(vector<SAnswer> answer) { this->answer = answer; }
	vector<SAnswer> get_answers() { return answer; }
protected:
    int id;
    string question;
    vector<SAnswer> answer;
    bool curr;  // ??????????????????? wtfwftwtf    
};

class CTest {
public:      
    CTest() { current_quest = 0; }
	CTest(CTest const & to_copy) {}
    void setup( QAB * qb );
    void add_quest(int id, string questtext);
    void add_answ(int qid, string text, int posid, bool curr); // question id, text, position id, is it true answer?
	void end_setup() { proverk.setup( quest.size() ); }
    void check_curr(int qid, int aid) { proverk.insert_answ(qid,quest[qid].check_currency(aid)); }
	void next_quest() { current_quest++; }
	
    CQuestion* get_quest(int qid) { return &quest[qid]; }
	STAnswCounter* get_results() { return &proverk; }
	
	int quest_size() { return quest.size(); }
	int get_curquest() { return current_quest; }
protected:
    QAB * qb;
    STAnswCounter proverk;
    vector<CQuestion> quest;  
	int current_quest;
};

#endif
