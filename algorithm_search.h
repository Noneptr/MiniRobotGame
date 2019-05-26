#ifndef ALGORITHM_SEARCH_H
#define ALGORITHM_SEARCH_H

#include <queue>
#include "squaregrid.h"

using Queue = std::deque<point>;
using line = std::pair<point, point>;
using dict = std::vector<line>;

bool inDict(const point &p, const dict &d);
dict search_short_way(const SquareGrid &graph, const point &start, const point &target); // поиск кратчайшего пути в ширину


#endif // ALGORITHM_SEARCH_H
