#include "CTable.h"

void CTable::setup(QAB * qb,int w, int h)
{
    this->qb = qb;
    stolb.resize(w);
    for(int i=0;i<stolb.size();i++)
    {
        stolb[i].setup(qb,h);
    }
    strok_name.resize(h);

    for(int i=0;i<stolb.size();i++)
        for(int d=0;d<stolb[i].size();d++)
        {
            stolb[i].insert_data(SType(-1,"NULLA"),d);
        }
}

void CTable::set_stolb_name(int stid, string name)
{
    stolb[stid].set_name(name);
}

void CTable::set_strok_name(int stid, string name)
{
    strok_name[stid] = name;
}

void CTable::insert_data(SType data, cords pos)
{
    stolb[pos.x].insert_data(data,pos.y);
}

void CTable::add_data(SType data, string columnname)
{
    for(int i=0;i<stolb.size();i++)
        if(*(stolb[i].get_name()) == columnname)
        {
            stolb[i].add_data(data);
        }


}

SType CTable::get_data(cords pos)
{
    return *(stolb[pos.x].get_data(pos.y));
}

