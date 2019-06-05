#ifndef ALGORITHM_HELP_ROBOT_H
#define ALGORITHM_HELP_ROBOT_H

#include <QVector>
#include <QPair>
#include <queue>

using Queue = std::queue<QPair<int, int>>; // класс очередь

bool in_field(const QPair<int, int> &p, int wfield, int hfield); // проверка на вхождение точки в область
bool in_vector(const QPair<int, int> &p, const QVector<QPair<int, int>> &v); // проверка на вхождение точки
// в последовательность точек
QVector<QPair<int, int>> neighbours(const QPair<int, int> &p, int wfield, int hfield); // соседи по строке и столбцу для точки
/*Пример соседей точки

    ++x++
    +x#x+
    ++x++

"#" - точка p, "x" - сосед точки p, "+" - не сосед точки p
*/

#endif // ALGORITHM_HELP_ROBOT_H
