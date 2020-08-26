#include "EulerODE.h"

#include "BaseSystem.h"

void EulerODE::makeStep(BaseSystem &system, double timeStep)
{
    std::vector<double> deriv;
    system.getDeriv(deriv);
    std::vector<double> state;
    system.getState(state);

    scaleVector(deriv,timeStep);
    addVectors(state,deriv);

    system.setState(state);

    system.moveTime(timeStep);
}

