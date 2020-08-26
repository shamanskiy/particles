#pragma once

#include <QColor>

class Wall
{
public:
    Wall(double x0, double y0, double x1, double y1, QColor color = Qt::white, int thickness = 1);

    double x0() const { return x_0; }
    double y0() const { return y_0; }
    double x1() const { return x_1; }
    double y1() const { return y_1; }

    QColor color() const { return colour; }
    int thickness() const { return thick; }

    double nX() const { return n_X; }
    double nY() const { return n_Y; }

protected:
    double x_0;
    double y_0;

    double x_1;
    double y_1;

    QColor colour;
    int thick;

    double n_X;
    double n_Y;

};
