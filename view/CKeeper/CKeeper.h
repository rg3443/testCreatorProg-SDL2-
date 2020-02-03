#ifndef CKEEPER_H_INCLUDED
#define CKEEPER_H_INCLUDED

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
#include "../../model/CModel.h"


struct SCordsList {
	cords question_pos;
	vector<cords> answer_pos;
};

struct SQuestionList {
	CQuestion* quest;
	SCordsList poses;
};

struct STestData {
	vector<SQuestionList> question;
//	//	//	//	//
	STestData() {}
	void insert(CQuestion* qes) {
		SQuestionList buf;
		buf.quest = qes;
		cords support_;
		support_.x = 50;
		support_.y = 10;
		buf.poses.question_pos = support_;
		
		for(int i=0;i<qes->answer_size();i++)
		{
			support_.y += 150;
			buf.poses.answer_pos[i] = support_;
			
		}
		
		question.push_back(buf);
	}
};



class CKeeper {
public:
	CKeeper(){}
	void setup(QAB * qb);
	STestData get_data() { return test_data; }
protected:
	QAB * qb;
	//structur to fill
	STestData test_data;

	//taking data from
	CModel * model;
	CTest * test;
	
};

#endif
