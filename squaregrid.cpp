#include "squaregrid.h"

SquareGrid::SquareGrid(int w, int h)
    :_width(w), _height(h)
{
}

bool SquareGrid::inBounds(const point &p) const
{
    return (p.first >= 0) && (p.first < _width) && (p.second >= 0) && (p.second < _height);
}


bool SquareGrid::unpassable(const point &p) const
{
    for (const point &e: _walls)
    {
        if (e == p)
        {
            return true;
        }
    }

    return false;
}


list SquareGrid::neighbors(const point &p) const
{
    list _ans;
    list _nei;
    _nei.push_back(point(p.first - 1, p.second));
    _nei.push_back(point(p.first + 1, p.second));
    _nei.push_back(point(p.first, p.second - 1));
    _nei.push_back(point(p.first, p.second + 1));

    for (point &e: _nei)
    {
        if (inBounds(e) && !unpassable(e))
        {
            _ans.push_back(e);
        }
    }

    return _ans;
}
