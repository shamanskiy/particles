#pragma once

#include <QColor>
#include <QPointF>

#include <vector>

class Particle : public QPointF
{
public:
    Particle(double x = 0., double y = 0., double u = 0., double v = 0., double m = 1., QColor colour = Qt::green);

    double u() const {return m_u;}
    double v() const {return m_v;}

    double m() const {return mass;}

    double fx() const {return m_fx;}
    double fy() const {return m_fy;}

    void setU(double u) {m_u = u;}
    void setV(double v) {m_v = v;}

    void setFx(double fx) {m_fx = fx;}
    void setFy(double fy) {m_fy = fy;}

    void addFx(double fx) {m_fx += fx;}
    void addFy(double fy) {m_fy += fy;}

    QColor colour() const {return color;}

    void pushWall(bool position) { wallsPositions.push_back(position); }
    bool wallPos(int wallNum) const { return wallsPositions[wallNum]; }

protected:

    double m_u;
    double m_v;

    double mass;

    double m_fx;
    double m_fy;

    QColor color;

    std::vector<bool> wallsPositions;

};
