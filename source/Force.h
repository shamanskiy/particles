#pragma once

#include "Particle.h"

#include <list>

class Particle;

struct force_type
{
    enum type
    {
        gravity = 0,
        drag = 1,
        attractor
    };
};

class Force
{
public:
    Force(force_type::type type = force_type::gravity, double param = -9.8);

    Force(force_type::type type,
          double param1,
          double param2,
          double param3);

    void apply(std::vector<Particle> & particles, int time = 0);

protected:

    force_type::type m_type;
    std::vector<double> coefs;
};
