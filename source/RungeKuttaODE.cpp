#include "RungeKuttaODE.h"

#include "BaseSystem.h"

void RungeKuttaODE::makeStep(BaseSystem &system, double timeStep)
{
    std::vector<double> state;
    system.getState(state);


    std::vector<double> stage1;
    system.getDeriv(stage1);
    scaleVector(stage1,timeStep);

    std::vector<double> temp;
    scaleVectorInto(stage1,0.5,temp);
    addVectors(temp,state);
    system.setState(temp);
    system.moveTime(timeStep/2);

    std::vector<double> stage2;
    system.getDeriv(stage2);
    scaleVector(stage2,timeStep);

    scaleVectorInto(stage2,0.5,temp);
    addVectors(temp,state);
    system.setState(temp);

    std::vector<double> stage3;
    system.getDeriv(stage3);
    scaleVector(stage3,timeStep);

    scaleVectorInto(stage3,1.,temp);
    addVectors(temp,state);
    system.setState(temp);
    system.moveTime(timeStep/2);

    std::vector<double> stage4;
    system.getDeriv(stage4);
    scaleVector(stage4,timeStep/6.);

    scaleVector(stage1,1./6.);
    scaleVector(stage2,1./3.);
    scaleVector(stage3,1./3.);

    addVectors(state,stage1);
    addVectors(state,stage2);
    addVectors(state,stage3);
    addVectors(state,stage4);

    system.setState(state);
}

