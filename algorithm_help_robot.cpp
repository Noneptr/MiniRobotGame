#include "algorithm_help_robot.h"

bool in_map(const QPair<int, int> &p, int wfield, int hfield)
{
    if ((p.first >= 0) && (p.first < wfield) && (p.second >= 0) && (p.second < hfield))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool in_vector(const QPair<int, int> &p, const QVector<QPair<int, int>> &v)
{
    for (const QPair<int, int> &e: v)
    {
        if (e == p)
        {
            return true;
        }
    }

    return false;
}

QVector<QPair<int, int>> neighbours(const QPair<int, int> &p, int wfield, int hfield)
{
    QPair<int, int> n1(p.first - 1, p.second);
    QPair<int, int> n2(p.first + 1, p.second);
    QPair<int, int> n3(p.first, p.second - 1);
    QPair<int, int> n4(p.first, p.second + 1);

    QVector<QPair<int, int>> result;

    if (in_map(n1, wfield, hfield))
    {
        result.push_back(n1);
    }

    if (in_map(n2, wfield, hfield))
    {
        result.push_back(n2);
    }

    if (in_map(n3, wfield, hfield))
    {
        result.push_back(n3);
    }

    if (in_map(n4, wfield, hfield))
    {
        result.push_back(n4);
    }

    return result;
}
