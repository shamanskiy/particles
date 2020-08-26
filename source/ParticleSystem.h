#pragma once

#include <list>
#include <vector>

#include "Particle.h"
#include "BaseSystem.h"
#include "Force.h"
#include "Wall.h"

class ParticleSystem : public BaseSystem
{
public:
    ParticleSystem();

    const std::vector<Particle> & getParticles()
    {
        return particles;
    }

    const std::vector<Wall> & getWalls()
    {
        return walls;
    }

    virtual void getDeriv(std::vector<double> & deriv);
    virtual void getState(std::vector<double> & state);
    virtual bool setState(std::vector<double> & state);

    int size() {return particles.size();}

    void checkWalls();

protected:

    virtual void computeForces();
    virtual void clearForces();

    void setWallParticles();

protected:

    using BaseSystem::time;

    std::vector<Particle> particles;
    std::vector<Force> forces;
    std::vector<Wall> walls;
};
