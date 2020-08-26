#include "Force.h"
#include <math.h>

Force::Force(force_type::type type, double param)
    : m_type(type)
{
    coefs.push_back(param);
}

Force::Force(force_type::type type,
             double param1,
             double param2,
             double param3)
    : m_type(type)
{
    coefs.push_back(param1);
    coefs.push_back(param2);
    coefs.push_back(param3);
}

void Force::apply(std::vector<Particle> & particles, int time)
{
    if (m_type == force_type::gravity)
    {
        for (auto & it : particles)
        {
            it.addFx(0.);
            it.addFy(-1*it.m()*coefs[0]);
        }
    }

    if (m_type == force_type::drag)
    {
        for (auto & it : particles)
        {
            it.addFx(-1*coefs[0]*it.u());
            it.addFy(-1*coefs[0]*it.v());
        }
    }

    if (m_type == force_type::attractor)
    {
        for (auto & it : particles)
        {
            double r2 = (it.x()-coefs[0])*(it.x()-coefs[0]) + (it.y()-coefs[1])*(it.y()-coefs[1]);
            double dirX = (coefs[0]-it.x())/sqrt(r2);
            double dirY = (coefs[1]-it.y())/std::sqrt(r2);

            it.addFx(dirX*it.m()*coefs[2]/r2);
            it.addFy(dirY*it.m()*coefs[2]/r2);
        }
    }
}
