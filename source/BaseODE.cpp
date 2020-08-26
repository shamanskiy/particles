#include "BaseODE.h"

#include <iostream>

bool BaseODE::addVectors(std::vector<double> &A,
                         std::vector<double> &B)
{
    if (A.size() != B.size())
    {
        std::cout << "Wrong vectors' size.";
        return 0;
    }
    else
    {
        int size = A.size();
        for (int i = 0; i < size; ++i)
        {
            A[i] += B[i];
        }
        return 1;
    }
}

void BaseODE::scaleVector(std::vector<double> &A, double c)
{
    for (auto & it : A)
        it *= c;
}

void BaseODE::scaleVectorInto(std::vector<double> & A, double c, std::vector<double> & B)
{
    if (c == 1.)
    {
        B = A;
    }
    else
    {
        int size = A.size();
        B.resize(A.size());

        for (int i = 0; i < size; ++i)
        {
            B[i] = A[i]*c;
        }
    }
}

