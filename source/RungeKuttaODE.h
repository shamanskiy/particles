#pragma once

#include "BaseODE.h"

class RungeKuttaODE : public BaseODE
{
public:

    virtual void makeStep(BaseSystem & system, double timeStep);
};
