#pragma once

#include <QLabel>

class ParticleSystem;

class Drawer : public QLabel
{
    Q_OBJECT
public:
    Drawer(ParticleSystem & system, QWidget * parent = 0);

    void toggleMesh();


protected:
    virtual void paintEvent(QPaintEvent *event);

    void drawMesh(QPainter& painter);
    void drawParticles(QPainter& painter);
    void drawWalls(QPainter& painter);


protected:
    ParticleSystem & particles;
    bool isMesh;
    QLabel info;

};
