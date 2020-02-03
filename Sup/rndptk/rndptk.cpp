#include "rndptk.h"

Potok::Potok( int colvo,int star,int ende )
{
    setup(colvo,star,ende);
}

void Potok::setup( int colvo, int star,int ende )
{
    nums.resize(colvo);
    nums6.resize(colvo);
    r_ch6.resize(colvo);
    //cout << "sex\n" << nums.size();
    srand((unsigned)time(0));
    for(int i=0;i<nums.size();i++)
    {
        r_ch6[i] = rand() % 6 + 1;
        nums[i] = (rand()%(ende+1-star))+star; // Creates array with 99 random integers
        //cout << "Whole num#" << i << " is equal to " << nums[i] << endl;
        //
        //cout << "||START NUM#" << i << " ||\n";
        nums6[i].resize(6);
        for(int n=0;n<6;n++)
        {

            if(n==0) nums6[i][n] = nums[i] / 100000;
            else if(n==1) nums6[i][n] = nums[i] / 10000 % 10;
            else if(n==2) nums6[i][n] = (nums[i] / 1000 % 100) % 10;
            else if(n==3) nums6[i][n] = (nums[i] / 100 % 1000) % 10;
            else if(n==4) nums6[i][n] = (nums[i] / 10 % 10000) % 10;
            else if(n==5) nums6[i][n] = (nums[i] % 100000) % 10;
            //cout << "Number num#" << n << " in number num#" << i << " is equel " << nums6[i][n] << endl;
        }
        cout << "||END NUM#" << i << " ||\n";
    }



    //show();
    shuffle();
    //show();

}

void Potok::show()
{
    cout << "||\tSTART SHOW\t||" << endl;
    for(int k=0;k<nums.size();k++)
    {
        cout<<nums[k]<<endl; // Displays Array
    }
    cout << "||\tEND SHOW\t||" << endl;
}

int Potok::get_next(const char* type)
{
    if(type=="WHOLE") {
        iterator++;
        if(iterator>=nums.size()) { iterator=0; return nums[ nums.size()-1 ]; }
        else return nums6[ iterator-1 ][ r_ch6[iterator-1] ];
    } else {
        iterator++;
        if(iterator>=nums.size()) { iterator=0; return nums6[ nums6.size()-1 ][ r_ch6[r_ch6.size()-1] ]; }
        else return nums6[ iterator-1 ][ r_ch6[iterator-1] ];
    }
}

int Potok::get_next()
{
    if(iterator>=nums.size()) { iterator=0; return nums[ nums.size()-1 ]; }
    else return nums6[ iterator-1 ][ r_ch6[iterator-1] ];    
}

void Potok::shuffle()
{
    for(int x=0;x<12;x++)
    for(int i=0;i<nums.size();i=i+2)
    {
        if(i != (nums.size()-1)) {
            int buf = nums[i];
            int buf2 = nums[i+1];
            nums[i] = buf2;
            nums[i+1] = buf;
        } else {
            int buf = nums[i];
            int buf2 = nums[0];
            nums[i] = buf2;
            nums[0] = buf;
        }
    }
}

/*

void Potok::setup( int colvo, int star,int ende )
{
    nums.resize(colvo);
    cout << "sex\n" << nums.size();
    srand((unsigned)time(0));
    for(int i=0;i<nums.size();i++)
    {
        nums[i] = (rand()%(ende+1-star))+star; // Creates array with 99 random integers
    }
    show();
    shuffle();
    show();

}

void Potok::show()
{
    cout << "||\tSTART SHOW\t||" << endl;
    for(int k=0;k<nums.size();k++)
    {
        cout<<nums[k]<<endl; // Displays Array
    }
    cout << "||\tEND SHOW\t||" << endl;
}

int Potok::get_next()
{
    iterator++;
    if(iterator>=nums.size()) { iterator=0; return nums[nums.size()-1]; }
    else return nums[iterator-1];

}

void Potok::shuffle()
{
    for(int x=0;x<12;x++)
    for(int i=0;i<nums.size();i=i+2)
    {
        if(i != (nums.size()-1)) {
            int buf = nums[i];
            int buf2 = nums[i+1];
            nums[i] = buf2;
            nums[i+1] = buf;
        } else {
            int buf = nums[i];
            int buf2 = nums[0];
            nums[i] = buf2;
            nums[0] = buf;
        }
    }
}

*/
