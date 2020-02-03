#include "CDrawer.h"

void CDrawer::draw(int question_id, CModel * model)
{
	const int START_POINT_X = 50;
	const int START_POINT_Y = 10;
	//print textures
	//this->DrawImage();
	//screen :
	//	w = 1200 h = 650
	//	otstuph = 20
	//	mirrototstupw = 50
	this->SetColorKey(White);
	if(!model->is_show_results_time())
		this->draw_question(question_id,model);
	else 
		this->draw_results(model);

}

void CDrawer::draw_question( int question_id, CModel * model )
{
	CTest * test = nullptr;
	CQuestion * current_question = nullptr;
	test = model->get_test();
	const int SCREEN_W = 1200;
	const int SCREEN_H = 650;
	this->DrawImage("misc/bw_rocks_2.bmp",cords(0,0),cords(SCREEN_W,SCREEN_H));
	this->DrawImage("misc/fm_small_logo.bmp",cords(0,0),cords(25,25));
	
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
	
	try {
		//rusrend.DrawRusText(questext, test_data.question[question_id].poses.question_pos);
		this->printbutton(questext,question_pos,cords(w,h/2),GHOSTBUTT,WHITE);
	
		question_pos.y += 60;
		for(int i=0; i<current_question->answer_size(); i++)
		{
			string answer_text = current_question->get_answer(i)->get_text();
			this->printbutton(answer_text,question_pos,cords(w,h),GHOSTBUTT,WHITE);
			question_pos.y += 150;
		//	printf("position is X%d Y%d\n", question_pos.x,question_pos.y);
		}
	}	
	catch(const char* eror) { printf(eror); } 
	
}

void CDrawer::draw_results( CModel * model )
{
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
		
		this->DrawText("TEST WAS PASSED. RESULTS :",question_pos,Black,64);
		question_pos.y += 160;
		this->DrawText(st_ammount_q,question_pos,Black,32);
		question_pos.y += 150;
		this->DrawText(st_minimum_ta,question_pos,Black,32);
		question_pos.y += 150;
		this->DrawText(st_current_ta,question_pos,Black,32);
		//
	}	
}

void CDrawer::printbutton(string text,cords pos, cords wh, int button_code, int tex_color_code)
{
	
	string image_path;
	int x_smesh,y_smesh;
	bool texture_button;
	switch(button_code)
	{
	case REDBUTT:
		image_path = "misc/red_button.bmp";
		x_smesh = 10;
		y_smesh = 10;
		texture_button = true;
	break;
	case YELLOWBUTT:
		image_path = "misc/yellow_button.bmp";
		x_smesh = 50;
		y_smesh = 30;
		texture_button = true;
	break;
	case GHOSTBUTT:
		this->DrawFillRect(cords(pos.x+5,pos.y+5),cords(pos.x+wh.x-5,pos.y+wh.y-5),typecolor(70,70,70));
		this->DrawOutRect(pos,cords(pos.x+wh.x,pos.y+wh.y),White);
		x_smesh = 40;
		y_smesh = 15;
		texture_button = false;
	break;
	}
	//cout << text << endl;
	if(texture_button)
	{ 
		this->DrawImage(image_path,pos,cords(pos.x+wh.x,pos.y+wh.y));
	}
	rusrend->DrawOtfText(text.c_str(),cords(pos.x+x_smesh,pos.y+y_smesh),16,BLACK);
	//this->DrawText(text,cords(pos.x+x_smesh,pos.y+y_smesh),typecolor(0,0,0),32);
}

void CDrawer::test_func()
{
	int xpos = 10;
    OTF_render otfcast;
	otfcast.setup(qb);

	otfcast.DrawOtfText("проверка номер два",cords(xpos,10),16, BLACK);

}
