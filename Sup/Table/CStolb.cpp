#include "CStolb.h"
void CStolb::setup(QAB * qb, int ammount_tiles)
{
    this->qb = qb;
    tile.resize(ammount_tiles);
}

void CStolb::insert_data(SType value, int tile_id)
{
    try {
        if(tile_id >= tile.size()) throw "ERROR: OUTRANGED MASSIFF\n";
        tile[tile_id] = value;
    }
    catch(const char* eror) { printf(eror); }
}

void CStolb::add_data(SType data)
{
    tile.push_back(data);
}
