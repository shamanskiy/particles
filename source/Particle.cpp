#include "Particle.h"

Particle::Particle(double x, double y,
                   double u, double v,
                   double m, QColor colour)
    : QPointF(x,y), m_u(u), m_v(v), mass(m),
      color(colour)
{


}

