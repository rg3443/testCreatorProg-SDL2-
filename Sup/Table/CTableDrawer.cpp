#include "CTableDrawer.h"

CTableDrawer::CTableDrawer(QAB * qb,CTable * table,cords pos, int tw , int th, SDL_Color clr)
{
    this->setup(qb);
    draw_table(table,pos,tw,th,clr);
}

void CTableDrawer::setup(QAB * qb)
{
    this->qb = qb;
    cast.setup(qb->get_etrnd());
    grf.setup(qb->get_etrnd(),qb->get_wnd());
}

void CTableDrawer::draw_table( CTable * table,cords pos, int tw, int th,SDL_Color clr)
{
    Viewport port(pos.x,pos.y,(tw*table->stolb_size())+1,(th*table->strok_size())+1,*(qb->get_etrnd()) );
    //  zagalovki
    int zx,zy;
    zx = tw + (tw / 10);
    zy = th / 10;
    for(int i=0;i<table->stolb_size();i++)
    {
        string stname = table->get_stolb_name(i);
        cast.DrawText(stname, zx,zy,10,10,Red,16);
        zx += tw;
    }
    cout << "we here1\n";
    zx = tw / 10;
    zy = th + (th / 10);
    for(int i=0;i<table->strok_size();i++)
    {
        string stname = table->get_strok_name(i);
        cast.DrawText(stname,zx,zy,10,10,Red,16);
        zy += th;
    }
    cout << "we here2\n";
    //  karkas draw
    int x,y;
    x = 0;
    y = 0;
    for(int i=0;i<table->stolb_size();i++)
    {
        x = 0;
        for(int d=0;d<table->strok_size();d++)
        {
            grf.baseSquare(cords(x,y),cords((x+tw),(y+th)),clr);
            x += tw;
        }
        y += th;
    }
    cout << "we her3e\n";
    // data draw
    x = tw + (tw / 4);
    y = th + (th / 4);
    for(int i=0;i<table->stolb_size();i++)
    {
        x = tw;
        for(int d=0;d<table->strok_size();d++)
        {
            SType data = table->get_data(cords(d,i)); cout << "we here31\n";
            if(data.value != -1) { cast.DrawPeremen("",data.value,x,y,10,10,Red,16);  cout << "we here321\n";}
            else if(data.text != "NULLA") { cast.DrawText(data.text,x,y,10,10,Red,16); cout << "we here322\n";}
            x += tw;
        }
        y += th;
    }
    cout << "we here4\n";
}
