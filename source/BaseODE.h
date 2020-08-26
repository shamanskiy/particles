#pragma once

#include <vector>

class BaseSystem;

class BaseODE
{
public:
    BaseODE() {}

    virtual void makeStep(BaseSystem & system, double timeStep) = 0;

    // add two vectors, result in the first
    bool addVectors(std::vector<double> & A, std::vector<double> & B);
    void scaleVector(std::vector<double> & A, double c);
    void scaleVectorInto(std::vector<double> & A, double c, std::vector<double> & B);
};
