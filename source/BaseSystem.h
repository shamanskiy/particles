#pragma once

#include <vector>

class BaseSystem
{
public:
    BaseSystem() {}

    // gather the system's derivatives into the vector
    virtual void getDeriv(std::vector<double> & deriv) = 0;
    // gather the system's phase state into the vector
    virtual void getState(std::vector<double> & state) = 0;
    // set the info from the vector as the system's phase state
    virtual bool setState(std::vector<double> & state) = 0;

    virtual void moveTime(double t) {time += t;}

protected:

    virtual void computeForces() = 0;
    virtual void clearForces() = 0;

protected:

    double time = 0.;
};

