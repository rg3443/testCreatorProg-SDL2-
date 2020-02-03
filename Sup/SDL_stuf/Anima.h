#ifndef ANIMA_H_INCLUDED
#define ANIMA_H_INCLUDED

struct anim_loader {
       vector<string> cadr;       
};

/*
anim_loader an;
an.cadr.resize(2);
an.cadr[0] = ".bmp";
an.cadr[1] = ".bmp";
*/

class Anima {
public:
    Anima(int x,int y,anim_loader cadrs);
    void move(int dir);
           
protected:
    anim_loader cadrs;
    cords crd;      
    customSDL cast;
};

#endif
