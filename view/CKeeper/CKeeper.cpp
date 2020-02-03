#include "CKeeper.h"

void CKeeper::setup(QAB * qb)
{
	printf("\tSTATUS : VIEW KEEPER INIT START\n");
	this->qb = qb;
	model = qb->get_model();
	test = model->get_test();
	for(int i=0;i<test->quest_size();i++)
	{
		printf("\t\tSTATUS : inserting test data...\n");
		//test_data.insert(test->get_quest(i));
		//printf("\t\tSTATUS : test data is %s\n",test_data.question[i].quest->get_text().c_str());
	}
	
}
