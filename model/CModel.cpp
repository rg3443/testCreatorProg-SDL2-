#include "CModel.h"

void CModel::setup(QAB * qb)
{
	this->qb = qb;
	qb->insert_model(this);
	printf("\tSTATUS : MODEL INIT STARTED\n");

	//
	test.add_question("в CHEVROLET TAHOE система MAGNETIC RIDE CONTROL отвечает за");
		test.add_answer(0,"адаптацию работы подвески к дорожным условиям",true);
		test.add_answer(0,"адаптацию работы подвески при спуске и подьеме",false);
		test.add_answer(0,"изменение реактивного усилия на руле",false);
		test.add_answer(0,"изменение фаз газораспределения в зависимости от режима работы",false);
	test.add_question("подвеска CADILLAC ESCALADE (K2XX)");
        test.add_answer(1,"передняя - независимая многорычажная со стабилизатором поперечной устойчивостиб, задняя - 5ти рычажная со спиральными пружынками",false);
        test.add_answer(1,"передняя - McPherson, задняя - полузависимая с торсионной балкой",false);
        test.add_answer(1,"передняя - McPherson, задняя - зависимая(мост)",false);
        test.add_answer(1,"правильный ответ отсутствует",true);
        
	/*
	test.add_question("this is test question?");
		test.add_answer(0,"currect answer",true);
		test.add_answer(0,"yes",false);
		test.add_answer(0,"no",false);
		test.add_answer(0,"friend call",false);
	test.add_question("the end");
		test.add_answer(1,"congrats",true);
		test.add_answer(1,"grats grats..",false);
		test.add_answer(1,"grats grats..",false);
		test.add_answer(1,"grats grats..",false);
		
	test.add_question("or not?");
		test.add_answer(2,"actually yes", true);
		test.add_answer(2,"not",false);
		test.add_answer(2,"not at all",false);
		test.add_answer(2,"really not",false);
	*/
	//
	const int QUESTION_AMMOUNT = 2;
	const int MINIMUM_POINTS = 2;
	proverka.setup(QUESTION_AMMOUNT,MINIMUM_POINTS);
}

void CModel::check_answer(int qid, int aid)
{
	proverka.add_answer_status(test.check_answer(qid,aid)); // wtf? more explanation pls
	test.next_question();
	if(proverka.is_test_done())
	{
		// show rezults
		show_results_time = true;
	}
}
