#pragma once

#include "BaseODE.h"

class EulerODE : public BaseODE
{
public:
    
    virtual void makeStep(BaseSystem & system, double timeStep);
};
