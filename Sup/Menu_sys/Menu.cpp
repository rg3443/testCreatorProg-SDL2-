#include "Menu.h"

void Menu::setup(QAB* qb,int name)
{
    this->qb = qb;
	this->name2 = name;
	base_status * buf = &(this->name);
	buf->place = name2;
	//Model * modela = qb->get_mod();
    //vector<car_list> cars;
    //cars = modela->get_carlist();
    /*
    int current_y, current_x;
    int day_counter;
    int y_tex,x_tex;
    int car_counter;
    int id_text_counter;
    int y_for_cars;
	switch(name)
	{
	case MAIN:
		lines.resize(50);
		texts.resize(75);
        butt.resize(4);

		lines[0].p[0].x = 0;
		lines[0].p[0].y = 350;
		lines[0].p[1].x = SCREEN_W;
		lines[0].p[1].y = 350;

		 current_y = 350;
		for(int lineY=1;lineY<12;lineY++)
        {
            lines[lineY].p[0].x = 0;
            lines[lineY].p[0].y = current_y;
            lines[lineY].p[1].x = SCREEN_W;
            lines[lineY].p[1].y = current_y;
            current_y = current_y + 50;
        }

        lines[12].p[0].x = 36; // ноемр
        lines[12].p[0].y = 350;
        lines[12].p[1].x = 36;
        lines[12].p[1].y = 900;

        lines[13].p[0].x = 166; // модель
        lines[13].p[0].y = 350;
        lines[13].p[1].x = 166;
        lines[13].p[1].y = 900;

         current_x = 190; // числа мес€ца
         day_counter = 1;
        for(int lineX=14;lineX<45; lineX++)
        {
            lines[lineX].p[0].x = current_x;
            lines[lineX].p[0].y = 350;
            lines[lineX].p[1].x = current_x;
            lines[lineX].p[1].y = 900;

            if(lineX < 23)
                texts[lineX].point.x = current_x - 20;
            else
                texts[lineX].point.x = current_x - 30;
            texts[lineX].point.y = 355;
            stringstream ss;
            ss << day_counter;
            texts[lineX].symbols = ss.str();

            current_x = current_x + 35;
            day_counter++;


        }


		texts[46].point.x = 5;
		texts[46].point.y = 355;
		texts[46].symbols = "#";

        texts[45].point.x = 41;
        texts[45].point.y = 355;
        texts[45].symbols = "GOSNUM";


         y_tex = 405;  car_counter = 1;
        for(int id_text=47;id_text<57; id_text++)
        {
            texts[id_text].point.x = 5;
            texts[id_text].point.y = y_tex;
            stringstream ss1;
            ss1 << car_counter;
            texts[id_text].symbols = ss1.str();
            y_tex = y_tex + 50;
            car_counter++;
        }
         id_text_counter = 57;  y_for_cars = 405;
        for(*set cars text info* int id_car = 0; id_car<CAR_AMMOUNT; id_car++)

        {
            texts[id_text_counter].point.x = 41;
            texts[id_text_counter].point.y = y_for_cars;
            texts[id_text_counter].symbols = cars[id_car].gosnum;
            id_text_counter++;
            y_for_cars = y_for_cars + 50;
        }
        cout << "last text_id is " << id_text_counter << endl;

        texts[68].point.x = 30;
        texts[68].point.y = 30;
        texts[68].symbols = "YEAR";
        butt[0].setup( 130,30,50,30,name,MINUS_Y,"<<" );
        butt[1].setup( 210,30,50,30,name,PLUS_Y,">>" );
        texts[69].point.x = 30;
        texts[69].point.y = 60;
        texts[69].symbols = "MONTH";
        butt[2].setup( 130,60,50,30,name,MINUS_M,"<" );
        butt[3].setup( 210,60,50,30,name,PLUS_M,">" );
	break;
	case SEAL_AWAY:
		lines.resize(4);
		butt.resize(7);
		texts.resize(12);
		//	LINES
		lines[0].p[0].x = 130;
		lines[0].p[0].y = 0;
		lines[0].p[1].x = 130;
		lines[0].p[1].y = 100;
		//
		lines[1].p[0].x = 0;
		lines[1].p[0].y = 100;
		lines[1].p[1].x = 260;
		lines[1].p[1].y = 100;
		//
		lines[2].p[0].x = 260;
		lines[2].p[0].y = 0;
		lines[2].p[1].x = 260;
		lines[2].p[1].y = 350;
		//
		lines[3].p[0].x = 0;
		lines[3].p[0].y = 350;
		lines[3].p[1].x = 260;
		lines[3].p[1].y = 350;
		//	//
		//	TEXTS
		texts[0].point.x = 15;
		texts[0].point.y = 15;
		texts[0].symbols = "MODEL :";

		texts[1].point.x = 55;
		texts[1].point.y = 15;
		texts[1].symbols = "GOSNUM :";

		texts[2].point.x = 145;
		texts[2].point.y = 15;
		texts[2].symbols = "|CURRENT DATE|";

		texts[3].point.x = 15;
		texts[3].point.y = 115;
		texts[3].symbols = "SEAL ";

		texts[4].point.x = 15;
		texts[4].point.y = 155;
		texts[4].symbols = "TYPE ";

		butt[3].setup(130,100,125,50,name,HERE_TYPE,"CLEAR");
		butt[4].setup(130,150,125,50,name,BRON_TYPE,"BRON");
		butt[5].setup(130,200,125,50,name,GIVE_TYPE,"GIVE");

		texts[5].point.x = 15;
		texts[5].point.y = 265;
		texts[5].symbols = "TIME :";

		texts[5].point.x = 170; // model->get_sealam(); кол-во выбранных дней
		texts[5].point.y = 270;
		texts[5].symbols = "0d";
		butt[0].setup(130,270,35,20,name,MINUS_AM_SEAL,"<<");
		butt[1].setup(225,270,35,20,name,PLUS_AM_SEAL,">>");

		butt[2].setup(130,290,130,40,name,ACCEPT_SEAL,"ACCEPT");

	break;
	}
	cout << "last text_i121212e12e12ed is " << id_text_counter << endl;
	*/
}

void Menu::add_button(int x,int y,int w,int h,int place,int dir, const char* text)
{
    /*
	Button new_button;
	new_button.setup(x,y,w,h,place,dir, text);
	butt.push_back(new_button);
	*/
}


