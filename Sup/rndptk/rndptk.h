#ifndef RNDPTK_H_INCLUDED
#define RNDPTK_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;
class Potok {
public:
    Potok() {}
    Potok(int colvo, int star, int ende);
    void setup(int colvo,int star,int ende);
    void show();
    int get_next(const char* type);
    int get_next();
    void shuffle();
protected:
    vector<int> nums;
   vector<vector<int> > nums6;
   vector<int> r_ch6;
    int iterator;
};


/*

using namespace std;
class Potok {
public:
    Potok() {}
    void setup(int colvo,int star,int ende);
    void show();
    int get_next();
    void shuffle();
protected:
    vector<int> nums;
    int iterator;
};

*/


#endif // RNDPTK_H_INCLUDED
