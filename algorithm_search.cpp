#include "algorithm_search.h"

bool inDict(const point &p, const dict &d)
{
    for (const line &e: d)
    {
        if (e.first == p)
        {
            return true;
        }
    }

    return false;
}

dict search_short_way(const SquareGrid &graph, const point &start, const point &target)
{
    Queue frontier; // очередь точек
    frontier.push_back(start);
    dict way;
    way.push_back(line(start, point(-1, -1)));

    while (!frontier.empty())
    {
        point current = frontier.back();
        frontier.pop_back();

        if (current == target)
        {
            break;
        }

        for (point next : graph.neighbors(current))
        {
            if (!inDict(next, way))
            {
                frontier.push_back(next);
                way.push_back(line(next, current));
            }
        }
    }

    return way;
}
