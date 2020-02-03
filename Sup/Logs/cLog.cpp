#include "cLog.h"
void Logys::open(const char * path)
{
    f_path = path;
}

string Logys::read(int line)
{
                try {
                    ifstream fin(f_path.c_str());
                    if(!fin.is_open()) { throw "file isnt opened\n"; return "";}
                    int i=0;
                    for(i=0;i<line;i++)
                    {
                        getline(fin,s_text);
                    }
                    fin.close();
                    return s_text;
                }
                catch(const char * eror) { printf(eror); }
}

void Logys::write( const char * text )
{
    try {
                ofstream fout;
                fout.open(f_path.c_str(), ios::app);
                if( !fout.is_open() ) { throw "file isnt opened\n"; return;}
                fout << text;
                fout.close();
    }
    catch(const char * eror) { printf(eror); }
}

void Logys::clear()
{
    try {
                ofstream fout;
                fout.open(f_path.c_str());
                if( !fout.is_open() ) { throw "file isnt opened\n"; return;}
                fout << "";
    }
    catch(const char * eror) { printf(eror); }
}

int Logys::sizes()
{
    try {
                ifstream fin;
                fin.open(f_path.c_str());
                if( !fin.is_open() ) { throw "file isnt opened\n"; return -1;}
                int counter;
                while(fin.eof())
                {
                               counter++;
                }
                return counter;
    }
    catch(const char * eror) { printf(eror); }
}
