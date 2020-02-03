#include "CTestView.h"


void CTestView::setup(QAB * qb)
{
    this->qb = qb;
	base_graph_render.setup(qb->get_etrnd(),qb->get_etwnd());
	russian_text_render.setup(qb);
}

void CTestView::present(int question_id)
{
    CModel * model = qb->get_model();
	const int START_POINT_X = 50;
	const int START_POINT_Y = 10;
	//print textures
	//this->DrawImage();
	//screen :
	//	w = 1200 h = 650
	//	otstuph = 20
	//	mirrototstupw = 50
	base_graph_render.SetColorKey(White);
	if(!model->is_show_results_time())
		this->show_question(question_id);
	else
		this->show_results();
}

void CTestView::show_question(int question_id)
{
	CTest * test = nullptr;
	CQuestion * current_question = nullptr;
	CModel * model = qb->get_model();
	test = model->get_test();
	const int SCREEN_W = 1200;
	const int SCREEN_H = 650;
	base_graph_render.DrawImage("misc/bw_rocks_2.bmp",cords(0,0),cords(SCREEN_W,SCREEN_H));
	base_graph_render.DrawImage("misc/fm_small_logo.bmp",cords(0,0),cords(25,25));

	current_question = test->get_question(question_id);
	const int START_POINT_X = 50;
	const int START_POINT_Y = 10;
	int w,h;
	w = 1100;
	h = 150;
	string questext = current_question->get_text();
	cords question_pos;
	question_pos.x = START_POINT_X;
	question_pos.y = START_POINT_Y;
    //rusrend.DrawRusText(questext, test_data.question[question_id].poses.question_pos);
    this->printbutton(questext,question_pos,cords(w,h/2),WHITE);
    ////russian_text_render.DrawOtfText(questext.c_str(),cords(question_pos.x+15,question_pos.y+15),16,BLACK);
    question_pos.y += 60;
    for(int i=0; i<current_question->answer_size(); i++)
    {
        string answer_text = current_question->get_answer(i)->get_text();
        this->printbutton(answer_text,question_pos,cords(w,h),WHITE);
        question_pos.y += 150;
    }
}

void CTestView::show_results()
{
	CModel * model = qb->get_model();
	const int START_POINT_X = 50;
	const int START_POINT_Y = 10;
	//	esli pora pokazivat' resultati
	cords question_pos;
	question_pos.x = START_POINT_X;
	question_pos.y = START_POINT_Y;
	if(model->is_show_results_time())
	{
		//
		string st_ammount_q,st_minimum_ta,st_current_ta;
		stringstream ss_ammmount_q,ss_minimum_ta, ss_current_ta;
		ss_ammmount_q << model->get_ammount_questions();
		ss_minimum_ta << model->get_minimum_currect_answers();
		ss_current_ta << model->get_currect_answers();
		st_ammount_q = "QUESTIONS AMMOUNT : " + ss_ammmount_q.str();
		st_minimum_ta = "MINIMUM CURRECT ANSWERS : " + ss_minimum_ta.str();
		st_current_ta = "CURRENT CURRECT ANSWERS : " + ss_current_ta.str();
		//
		string gggg = "вы успешно прошли тест результаты";

		base_graph_render.DrawText("TEST WAS PASSED. RESULTS :",question_pos,Black,64);
		this->printbutton(gggg,question_pos,cords(500,500),2);
		//
	}
}

void CTestView::printbutton(string text,cords pos, cords wh, int tex_color_code)
{
    int x_smesh,y_smesh;
	base_graph_render.DrawOutRect(pos,cords(pos.x+wh.x,pos.y+wh.y),White);
	x_smesh = 40;
	y_smesh = 15;
	russian_text_render.DrawOtfText(text.c_str(),cords(pos.x+x_smesh,pos.y+y_smesh),32,WHITE);
}
