#ifndef GSDL_H_INCLUDED
#define GSDL_H_INCLUDED

struct SSDLTextParam {
    //  DATA TO DRAW FOR FUNC SDLprint
    vector<int> integer;
    vector<float> floater;
    vector<string> stringer;
    SSDLTextParam() {

    }
    SSDLTextParam(int i) { ins_int(i); }
    SSDLTextParam(float f){ ins_float(f); }
    SSDLTextParam(string s) { ins_string(s); }
    SSDLTextParam(int i, string s) { ins_int(i); ins_string(s); }
    SSDLTextParam(float f, string s) { ins_float(f); ins_string(s); }
    SSDLTextParam(int i, float f) { ins_int(i); ins_float(f); }
    SSDLTextParam(int i,float f, string s)
    {
        ins_int(i);
        ins_float(f);
        ins_string(s);
    }

    void ins_int(int value) { integer.push_back(value); }
    void ins_float(float value) { floater.push_back(value); }
    void ins_string(string text) { stringer.push_back(text); }
};


struct SSurface {
    string file_path;
    SDL_Surface * surf;
    SDL_Rect rect;       
};

#endif
