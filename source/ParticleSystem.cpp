#include "ParticleSystem.h"

#include <iostream>

ParticleSystem::ParticleSystem()
{
    particles.push_back(Particle(-30.,0.,0.,-25.,1.,Qt::red));
    particles.push_back(Particle(30.,0.,0.,20.,2.,Qt::yellow));
    particles.push_back(Particle(90.,5.,-30.,0.,1.));

    //forces.push_back(Force(force_type::drag,.001));
    //forces.push_back(Force(force_type::gravity,9.8));
    forces.push_back(Force(force_type::attractor,0.,0.,30000.));

    walls.push_back(Wall(-100,-100,100,-100,Qt::red));
    walls.push_back(Wall(100,-100,100,100));
    walls.push_back(Wall(100,100,-100,100,Qt::red));
    walls.push_back(Wall(-100,100,-100,-100));

    setWallParticles();
}

void ParticleSystem::getDeriv(std::vector<double> &deriv)
{
    deriv.resize(4*size());
    clearForces();
    computeForces();
    int i = 0;
    for (auto & it : particles)
    {
        deriv[4*i] = it.u();
        deriv[4*i+1] = it.v();
        deriv[4*i+2] = it.fx()/it.m();
        deriv[4*i+3] = it.fy()/it.m();
        ++i;
    }
}

void ParticleSystem::getState(std::vector<double> &state)
{
    state.resize(4*size());
    int i = 0;
    for (auto & it : particles)
    {
        state[4*i] = it.x();
        state[4*i+1] = it.y();
        state[4*i+2] = it.u();
        state[4*i+3] = it.v();
        ++i;
    }
}

bool ParticleSystem::setState(std::vector<double> &state)
{
    if (state.size() != 4*size())
    {
        std::cout << "Can't set state. Wrong vector's size.\n";
        return 0;
    }
    else
    {
        int i = 0;
        for (auto & it : particles)
        {
            it.setX(state[4*i]);
            it.setY(state[4*i+1]);
            it.setU(state[4*i+2]);
            it.setV(state[4*i+3]);
            ++i;
        }
        return 1;
    }
}

void ParticleSystem::computeForces()
{
    for (auto & it : forces)
        it.apply(particles);
}

void ParticleSystem::clearForces()
{
    for (auto & it : particles)
    {
        it.setFx(0.);
        it.setFy(0.);
    }
}

void ParticleSystem::checkWalls()
{
    int i = 0;
    for (auto & w : walls)
    {
        double midX = (w.x0() + w.x1())/2.;
        double midY = (w.y0() + w.y1())/2.;

        for (auto & p : particles )
        {
            double dirX = p.x() - midX;
            double dirY = p.y() - midY;

            if ((dirX*w.nX() + dirY*w.nY() >= 0) != p.wallPos(i))
            {
                double nU = (p.u()*w.nX() + p.v()*w.nY())*w.nX();
                double nV = (p.u()*w.nX() + p.v()*w.nY())*w.nY();

                p.setU(p.u() - 2*nU);
                p.setV(p.v() - 2*nV);
            }
        }
        ++i;
    }
}

void ParticleSystem::setWallParticles()
{
    for (auto & w : walls)
    {
        double midX = (w.x0() + w.x1())/2.;
        double midY = (w.y0() + w.y1())/2.;

        for (auto & p : particles)
        {
            double dirX = p.x() - midX;
            double dirY = p.y() - midY;

            p.pushWall((dirX*w.nX() + dirY*w.nY() >= 0));
        }
    }
}
