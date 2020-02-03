#include "CInput.h"

void CInput::setup(CModel * model)
{
	this->model = model;
}

void CInput::check_input(bool * is_quit)
{
     
     
			pos.x = 50;
			pos.y = 70;
			 w = 1100;
			 h = 150;
	if( SDL_WaitEvent(&e) != 0 )
	{
		if(e.type == SDL_MOUSEBUTTONDOWN)
		{
			int mx,my;
			SDL_GetMouseState(&mx,&my);
			//cout << mx << "|" << my << endl;
			int answer_id_counter = -1; // answer button on screen id
			for(int i=0;i<4;i++)
			{
				answer_id_counter++;
				if(mx > pos.x && mx < (pos.x+w) && my > pos.y && my < (pos.y+h))
				{
					int current_question_id = model->get_current_question();
					model->check_answer(current_question_id,answer_id_counter);
					//current_question_id++;
					//model->set_current_question(current_question_id);
				}
				pos.y += h;
			}
		} else if(e.type == SDL_QUIT) {
			*is_quit = true;
		}
	}
}
