#ifndef SQUAREGRID_H
#define SQUAREGRID_H

#include <vector>
#include <utility>

using point = std::pair<int, int>;
using list = std::vector<point>;

class SquareGrid
{
private:
    int _width, _height;

public:
    list _walls;


public:
    SquareGrid(int w, int h);
    bool inBounds(const point &p) const; // проверка вхождения точки в поле
    bool unpassable(const point &p) const; // проверка на принадлежность к списку стен
    list neighbors(const point &p) const; // список сосдних точек данной
};

#endif // SQUAREGRID_H
