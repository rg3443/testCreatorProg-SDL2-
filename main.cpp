#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "presenter/CPresenter.h"
#include "Sup/SDL_stuf/baseSDL.h"
#include "Sup/SDL_stuf/OTF_render.h"
#include "view/CDrawer/CDrawer.h"
#include "Sup/LoadWindow/CLoadWindow.h"

#include "Sup/RussianFont/CRussianFont.h"

void BSDL_test(CDrawer * cast, SDL_Renderer * rend)
{
	while(true)
	{
		SDL_SetRenderDrawColor(rend,255,255,255,0);
		SDL_RenderClear(rend);
		//
            cast->printbutton("ààààààà",cords(),cords(),GHOSTBUTT,WHITE);
		//
		SDL_RenderPresent(rend);
	}
}

void CreateLoadScreen();
void DestroyLoadScreen();

void ProgInit(QAB * qb, CPresenter * pres);
void ProgStart(CPresenter * pres);
void ProgQuit(QAB * qb, CPresenter * pres);

int main(int argc, char *argv[])
{
	
	//CRussianFont rfont;
	//rfont.init();
	
    setlocale(LC_ALL, "Russian");
    
	CLoadWindow load_window;
//	load_window.setup("test",cords(10,10),cords(100,100));
	
    QAB question_answer_base;
    CPresenter presenter;

    baseSDL cast;

    ProgInit(&question_answer_base, &presenter);
	cast.setup(question_answer_base.get_etrnd(),question_answer_base.get_etwnd());
	//BSDL_test(&cast,question_answer_base.get_rnd());
    //SDL_Delay( 10000 );
  //  load_window.destroy();
    CDrawer dro;
    dro.insert_qab(&question_answer_base);
    dro.setup(question_answer_base.get_etrnd(),question_answer_base.get_etwnd());
   // BSDL_test(&dro,question_answer_base.get_rnd());
	//OTF_test(question_answer_base.get_etrnd(), &question_answer_base);
    ProgStart(&presenter);
    ProgQuit(&question_answer_base,&presenter);

    system("PAUSE");
    return EXIT_SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////

void CreateLoadScreen(CLoadWindow * loader)
{
	loader->setup("test",cords(10,10),cords(100,100));
	loader->draw_load_screen();
}

void DestroyLoadScreen(CLoadWindow * loader)
{
	loader->destroy();
}

////////////////////////////////////////////////////////////////////////////////
void ProgInit(QAB * qb, CPresenter * pres)
{
	printf("STATUS : INITIALIZATION	\n");
    qb->setup();
	printf("\tSTATUS : QAB INIT DONE\n");
    pres->setup(qb);
	printf("\tSTATUS : PRESENTER INIT DONE\n");
}

void ProgStart(CPresenter * pres)
{
	printf("STATUS : PROG IS RUNNING...\n");
    pres->prog_start();
}

void ProgQuit(QAB * qb,CPresenter * pres)
{
	printf("STATUS : QUITING PROG...\n");
    pres->prog_quit();
	printf("\tSTATUS : PRESENTER SUCCESFULLY QUITED\n");
    qb->quit_prog();
	printf("\tSTATUS : QAB SUCCESFULLY QUITED\n");
}
