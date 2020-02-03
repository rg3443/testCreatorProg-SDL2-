#include "CModel.h"

void CModel::setup(QAB * qb)
{
	this->qb = qb;
	qb->insert_model(this);
	printf("\tSTATUS : MODEL INIT STARTED\n");

	//
	test.add_question("� CHEVROLET TAHOE ������� MAGNETIC RIDE CONTROL �������� ��");
		test.add_answer(0,"��������� ������ �������� � �������� ��������",true);
		test.add_answer(0,"��������� ������ �������� ��� ������ � �������",false);
		test.add_answer(0,"��������� ����������� ������ �� ����",false);
		test.add_answer(0,"��������� ��� ����������������� � ����������� �� ������ ������",false);
	test.add_question("�������� CADILLAC ESCALADE (K2XX)");
        test.add_answer(1,"�������� - ����������� ������������� �� �������������� ���������� �������������, ������ - 5�� �������� �� ����������� ����������",false);
        test.add_answer(1,"�������� - McPherson, ������ - ������������� � ���������� ������",false);
        test.add_answer(1,"�������� - McPherson, ������ - ���������(����)",false);
        test.add_answer(1,"���������� ����� �����������",true);
        
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
