#ifndef CLOG_H_INCLUDED
#define CLOG_H_INCLUDED

#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;
//логирование
//берет любую инфу и запис. в файл
class Logys {
public:
                Logys() {}
                Logys(Logys * new_ob) {}

                void open(const char * path);
                string read(int line);
                void write(const char * text);
                void clear();
                int sizes();
                //void show(); void show(int line);
protected:
                const char * cc_text;
                string s_text;
                string f_path;
                //ofstream fout;
    //ifstream fin;
};


#endif // CLOG_H_INCLUDED
