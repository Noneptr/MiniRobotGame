#ifndef ALGORITHM_HELP_ROBOT_H
#define ALGORITHM_HELP_ROBOT_H

#include <QVector>
#include <QPair>
#include <queue>

using Queue = std::queue<QPair<int, int>>;

bool in_field(const QPair<int, int> &p, int wfield, int hfield);
bool in_vector(const QPair<int, int> &p, const QVector<QPair<int, int>> &v);
QVector<QPair<int, int>> neighbours(const QPair<int, int> &p, int wfield, int hfield);

#endif // ALGORITHM_HELP_ROBOT_H
