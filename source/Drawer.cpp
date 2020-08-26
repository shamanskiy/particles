#include "Drawer.h"

#include <QPainter>

#include <iostream>

#include "ParticleSystem.h"

Drawer::Drawer(ParticleSystem & system, QWidget * parent)
    : QLabel(parent),
      particles(system),
      isMesh(true),
      info(this)
{
    setPalette(QPalette(QColor(Qt::black)));
    setAutoFillBackground(true);

    info.raise();
}

void Drawer::drawParticles(QPainter &painter)
{
    for (auto& it : particles.getParticles())
    {
        painter.setPen(QPen(it.colour(),10*it.m()));
        painter.drawEllipse(it,3,3);
    }

}

void Drawer::drawMesh(QPainter &painter)
{
    painter.setPen(QPen(Qt::white,1,Qt::DashLine));

    int i = 1;
    int step = 50;
    while (step*i < width()/2)
    {
        painter.drawLine(QPoint(step*i,-1*height()/2),QPoint(step*i,height()/2));
        painter.drawLine(QPoint(-step*i,-1*height()/2),QPoint(-step*i,height()/2));
        ++i;
    }

    i = 1;
    while (step*i < height()/2)
    {
        painter.drawLine(QPoint(-1*width()/2,step*i),QPoint(width()/2,step*i));
        painter.drawLine(QPoint(-1*width()/2,-step*i),QPoint(width()/2,-step*i));
        ++i;
    }

    painter.setPen(QPen(Qt::white,2));
    painter.drawLine(QPoint(0,height()/-2),QPoint(0,height()/2));
    painter.drawLine(QPoint(width()/-2,0),QPoint(width()/2,0));
}

void Drawer::drawWalls(QPainter &painter)
{
    for (auto & it : particles.getWalls())
    {
        painter.setPen(QPen(it.color(),it.thickness()));
        painter.drawLine(QPoint(it.x0(),it.y0()),QPoint(it.x1(),it.y1()));
    }
}

void Drawer::toggleMesh()
{
    isMesh = !isMesh;
    update();
}

void Drawer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QMatrix m;
    m.translate(width()/2,height()/2);
    m.scale(1,-1);
    painter.setMatrix(m);

    if (isMesh)
        drawMesh(painter);

    drawWalls(painter);
    drawParticles(painter);
}
