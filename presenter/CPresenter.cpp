#include "CPresenter.h"

#include "../Sup/SDL_stuf/baseSDL.h"

void CPresenter::setup(QAB * qb)
{
	printf("\tSTATUS : PRESENTER INIT STARTED\n");
	this->qb = qb;
	model.setup(qb);
	printf("\tSTATUS : MODEL INIT DONE\n");
	input.setup(&model);
	printf("\tSTATUS : INPUT INIT DONE\n");
	screen_refresher.setup(qb->get_etrnd(),qb->get_etwnd(),typecolor(255,255,255));
	output.setup(qb);
	printf("\tSTATUS : VIEW INIT DONE\n");
}

void CPresenter::prog_start()
{
	baseSDL cast;
	cast.setup(qb->get_etrnd(),qb->get_etwnd());
	CTest * test = model.get_test();
	quit = false;
	
	string test_status;
	
	while(!quit)
	{
		int current_question = test->get_current_question();
		screen_refresher.enter();
		
		output.draw(current_question);
		//output.DrawImage("misc/fm_big_logo.bmp",cords(0,0),cords(1200,650));
		input.check_input(&quit);
		
		screen_refresher.exit();
	}
}

void CPresenter::prog_quit()
{

}
