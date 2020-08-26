#include "Wall.h"
#include <math.h>

Wall::Wall(double x0, double y0, double x1, double y1,
            QColor color, int thickness)
    : x_0(x0),
      y_0(y0),
      x_1(x1),
      y_1(y1),
      colour(color),
      thick(thickness)
{
    n_X = y_0 - y_1;
    n_Y = x_1 - x_0;
    double norm = sqrt(n_X*n_X + n_Y*n_Y);
    n_X = n_X/norm;
    n_Y = n_Y/norm;
}

